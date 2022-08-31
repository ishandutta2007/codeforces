/** Team Proof
Java template
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer tokenizer=null;
	
	public static void main(String[] args) throws IOException
	{
		new Main().execute();
	}
	
	void debug(Object...os)
	{
		System.out.println(Arrays.deepToString(os));
	}
	
	int ni() throws IOException
	{
		return Integer.parseInt(ns());
	}
	
	long nl() throws IOException 
	{
		return Long.parseLong(ns());
	}
	
	double nd() throws IOException 
	{
		return Double.parseDouble(ns());
	}
		
	String ns() throws IOException 
	{
		while (tokenizer == null || !tokenizer.hasMoreTokens()) 
			tokenizer = new StringTokenizer(br.readLine());
		return tokenizer.nextToken();
	}
	
	String nline() throws IOException
	{
		tokenizer=null;
		return br.readLine();
	}
		
	

	//Main Code starts Here
int totalCases, testNum;
int testnum;

int n;
long k;
long l[], r[];
long ls[], rs[];

void execute() throws IOException
{
	lucky=new long[1<<20]; 
	one = BigInteger.ONE;
	top=0;
	gen(0);
	Arrays.sort(lucky,0,top);
	
	totalCases = 1;
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if(!input())
			break;
		solve();
	}
}

long[] lucky;
long minlen;
int top;



void gen(long cur)
{
	if(cur > 1e18) return;
	if(cur!=0) lucky[top++]=cur;
	gen(cur*10+4);
	gen(cur*10+7);
}

BigInteger bcnt,ecnt,one,K;
BigInteger begcnt,endcnt;

int rsind[], lsind[];

BigInteger begSum(int a,int b)
{
	int begind = lsind[a];
	if(begind < 0)
		begind = -(begind+1);
		
	int endind = lsind[b];
	if(endind < 0)
		endind = -(endind+1);
		
	BigInteger sum = BigInteger.ZERO;
	for(int i=begind;i<endind;i++)
		sum = sum.add( BigInteger.valueOf(ls[i]-lucky[a]));
		
	begcnt = BigInteger.valueOf(endind - begind);
	return sum;
}
	
BigInteger endSum(int a,int b)
{
	int begind = rsind[a];
	if(begind < 0)
		begind = -(begind+1);
		
	int endind = rsind[b];
	if(endind < 0)
		endind = -(endind+1);
		
	BigInteger sum = BigInteger.ZERO;
	for(int i=begind;i<endind;i++)
		sum = sum.add( BigInteger.valueOf(lucky[b]-rs[i]));
		
	endcnt = BigInteger.valueOf(endind - begind);
	return sum;
}

boolean doit(int k)
{
	if(k>minlen) return false;
	long beg = lucky[0];
	long end = lucky[k-1];
	
	
	BigInteger curCost = BigInteger.ZERO;
	bcnt = BigInteger.ZERO;
	ecnt = BigInteger.ZERO;
	
	
	for(int i=0;i<n;i++)
	{
		if(l[i]>beg)
		{
			curCost = curCost.add( BigInteger.valueOf( l[i]-beg ));
			bcnt = bcnt.add(one);
		}
		if(r[i]<end)
		{
			curCost = curCost.add( BigInteger.valueOf( end-r[i] ));
			ecnt = ecnt.add(one);
		}
	}
	
	boolean debug = false;
	//if(k==1) debug=true;
	
	if(debug)
		debug(beg,end,curCost,bcnt,ecnt);
	
	if(end-beg+1 <= minlen && curCost.compareTo(K) <= 0)
	{
		//debug(k,curCost);
		return true;
	}
	
	for(int i=1;i+k<=top;i++)
	{
		long newbeg = lucky[i];
		long newend = lucky[i+k-1];
		
		BigInteger bs = begSum(i-1,i);
		BigInteger es = endSum(i+k-2,i+k-1);
		
		BigInteger term1 = ecnt .multiply(BigInteger.valueOf(newend-end)) . add( es );
		BigInteger term2 = (bcnt.subtract(begcnt)) .multiply(BigInteger.valueOf(newbeg-beg)) .add( bs );
		
		BigInteger newCost = curCost.add(term1).subtract(term2);
		if(newend-newbeg+1 <= minlen && newCost.compareTo(K) <= 0)
		{
			//debug(k,i,newbeg,newend,newCost);
			return true;
		}
		
		// if(i<=10)
		// {
			// debug("old range",beg,end,"old cnts",bcnt,ecnt,"old costs",curCost);
			// debug(i,"range",newbeg,newend,"cost",newCost,"begSum",bs,begcnt,"endSum",es,endcnt);
		// }
		
		curCost = newCost;
		ecnt = ecnt.add(endcnt);
		bcnt = bcnt.subtract(begcnt);
		end=newend;
		beg=newbeg;
		
	}
	
	return false;
}

void solve() throws IOException
{
	int lo=0;
	int hi=top;
	
	while(hi>lo)
	{
		int mid = (lo+hi+1)/2;

		if(doit(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	
	System.out.println(hi);
}

boolean input() throws IOException
{
	n=ni(); k=nl();
	//debug(n,k);
	K=BigInteger.valueOf(k);
	minlen = (long)(2e18);
	l=new long[n]; ls=new long[n];
	r=new long[n]; rs=new long[n];
	for(int i=0;i<n;i++)
	{
		
		l[i]=nl();	ls[i]=l[i];
		r[i]=nl();	rs[i]=r[i];
		//debug(l[i],r[i]);
		minlen = Math.min(minlen, r[i]-l[i]+1);
	}
	Arrays.sort(ls);
	Arrays.sort(rs);
	
	rsind = new int[top];
	lsind = new int[top];
	
	for(int i=0;i<top;i++)
	{
		rsind[i] = Arrays.binarySearch(rs,lucky[i]);
		lsind[i] = Arrays.binarySearch(ls,lucky[i]-1);
	}
	
	return true;
}


}