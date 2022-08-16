import java.io.*;
import java.util.*;


public class cf42e
{
	static int[] k;
	static int[][] v,t;
 
	static int solve(int a,int b)
	{
		int ca,cb,ia,ib,sum,i,tm;
		ca=0;
		cb=0;
		ia=0;
		ib=0;
		sum=0;
		
		
		int[] va=new int[k[a]];
		int[] ta=new int[k[a]];
		for(i=0;i<k[a];i++)
		{
			va[i]=v[a][i];
			ta[i]=t[a][i];
		}
		
		int[] vb=new int[k[b]];
		int[] tb=new int[k[b]];
		for(i=0;i<k[b];i++)
		{
			vb[i]=v[b][i];
			tb[i]=t[b][i];
		}
		
		while(true)
		{
			//System.out.println(ca+" "+cb+" "+ia+" "+ib);
			if(ia==k[a] || ib==k[b])	break;
			
			if(ca==cb)
			{
				sum++;
				if(ta[ia]>tb[ib])
				{
					ca+=va[ia]*tb[ib];
					cb+=vb[ib]*tb[ib];
					ta[ia]-=tb[ib];
					ib++;
				}
				else
				{
					ca+=va[ia]*ta[ia];
					cb+=vb[ib]*ta[ia];
					tb[ib]-=ta[ia];
					ia++;
				}
			}
			else
			{
				tm=Math.min(ta[ia],tb[ib]);
				if(ca<cb && ca+va[ia]*tm>cb+vb[ib]*tm)
						sum++;
				if(ca>cb && ca+va[ia]*tm<cb+vb[ib]*tm)
						sum++;
				if(ta[ia]>tb[ib])
				{
					ca+=va[ia]*tb[ib];
					cb+=vb[ib]*tb[ib];
					ta[ia]-=tb[ib];
					ib++;
				}
				else
				{
					ca+=va[ia]*ta[ia];
					cb+=vb[ib]*ta[ia];
					tb[ib]-=ta[ia];
					ia++;
				}
			}
		}
		return sum-1;
	}
 	
	
    public static void main(String[] args)
    throws Exception
    {
		Parser pr=new Parser(System.in);
		int i,j,n,s,ans=0;
		n=pr.ni();
		s=pr.ni();
		k=new int[n];
		v=new int[n][110];
		t=new int[n][110];
		for(i=0;i<n;i++)
		{
			k[i]=pr.ni();
			for(j=0;j<k[i];j++)
			{
				v[i][j]=pr.ni();
				t[i][j]=pr.ni();
			}
		}
		
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				ans+=solve(i,j);
			
		
		System.out.println(ans);
       
	   
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

       public int ni() throws Exception
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
       
       public long nl() throws Exception
       {
          long ret = 0;
          byte c = read();
          while (c <= ' ') c = read();
          boolean neg = c == '-';
          if (neg) c = read();
          do
          {
             ret = ret * 10 + c - '0';
             c = read();
          } while (c > ' ');
          if (neg) return ret;
          return ret;
       }
  
       public String ns() throws Exception
       {
          StringBuffer ret = new StringBuffer();
          byte c = read();
          while (c <= ' ') c = read();
          do
          {
             ret = ret.append((char)c);
             c = read();
          } while (c > ' ');
          return ret.toString();
       }

       private void fillBuffer() throws Exception
       {
          bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
          if (bytesRead == -1) buffer[0] = -1;
       }

       private byte read() throws Exception
       {
          if (bufferPointer == bytesRead) fillBuffer();
          return buffer[bufferPointer++];
       }
    }