/*
* Author: Nikhil Garg
* Date:   2010-10-18
*
*/
import java.io.*;
import java.util.*;
import java.math.*;





public class cf40b
{


	public static void main(String[] args) throws IOException
	{
		Parser pr=new Parser(System.in);
		int n,b,max,i,j;
		n=pr.ni();
		b=pr.ni();
		int[] a=new int[n];
		for(i=0;i<n;i++)
			a[i]=pr.ni();
		max=b;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				max=Math.max(max,b%a[i]+(b/a[i])*a[j]);
		System.out.println(max);
	}

	public static void input() throws IOException
	{

	}

	public static void solve() throws IOException
	{

	}
}


class Parser
{
       final private int BUFFER_SIZE = 1 << 16;

       private DataInputStream din;
       private byte[] buffer;
       private int bufferPointer, bytesRead;

       public Parser(InputStream in)
       {
          din = new DataInputStream(in);
          buffer = new byte[BUFFER_SIZE];
          bufferPointer = bytesRead = 0;
       }

       public int ni() throws IOException
       {
          int ret = 0;
          byte c = read();
          while (c <= ' ') c = read();
          boolean neg = c == '-';
          if (neg) c = read();
          do
          {
             ret = ret * 10 + c - '0';
             c = read();
          } while (c > ' ');
          if (neg) return -ret;
          return ret;
       }


       public String ns() throws IOException
       {
          StringBuffer ret=new StringBuffer();
          byte c = read();
          while (c <= ' ') c = read();
          do
          {
             ret.append((char)c);
             c = read();
          } while (c > ' ');
			return ret.toString();
       }

       private void fillBuffer() throws IOException
       {
          bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
          if (bytesRead == -1) buffer[0] = -1;
       }

       private byte read() throws IOException
       {
          if (bufferPointer == bytesRead) fillBuffer();
          return buffer[bufferPointer++];
       }
}