import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class R221qBPreparingForTheContest {

	static int n,m,s;
	static Bug bug[];
	static Student stud[]; 
	static int ans[];
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		m = ip(st1.nextToken());
	    s = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    bug = new Bug[m];
	    for(int i=0;i<m;i++)
	    	bug[i] = new Bug(i,ip(st2.nextToken()));
	     
	    stud = new Student[n];
	    for(int i=0;i<n;i++)
	    	stud[i] = new Student(i);
	    
	    StringTokenizer st3 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	stud[i].b = ip(st3.nextToken());
	    
	    StringTokenizer st4 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++)
	    	stud[i].c = ip(st4.nextToken());
	    
	    Arrays.sort(bug);
	    Arrays.sort(stud);
	    
	    //System.out.println(Arrays.deepToString(bug));
	    //System.out.println(Arrays.deepToString(stud));
	    
	    ans = new int[m];
	    
	    int time = binarySearchFirst(1,m+1);
	    
	    if(time == -1)
	    	w.println("NO");
	    else{
	    	w.println("YES");
	    	if(solve(time) == false)
	    		throw new Exception();
	    	for(int i=0;i<m;i++)
	    		w.print((ans[i]+1) + " ");
	    }
	    
	    w.close(); 
	}
	
	public static int binarySearchFirst(int start,int end){
		int ret = -1;
		while(true){
			if(start == end)	return ret;
			int mid = (start + end) >> 1;
	    	boolean res = solve(mid);
	    	if(res)	ret = mid;
	    	if(end - start == 1)	return ret;
	    	if(res)	end = mid;
	    	else	start = mid + 1;
		}
	}
	
	public static boolean solve(int days){
		if(days <= 0)	return false;
		
		PriorityQueue<Student> pq = new PriorityQueue<Student>(new StudentComparator());
		long pass = 0;
		int pBug = 0,pStud = 0;
		
		while(pBug < m){
			while(pStud < n){
				if(stud[pStud].b >= bug[pBug].a)
					pq.add(stud[pStud]);
				else
					break;
				pStud++;
			}
			if(pq.isEmpty())	return false;
			Student now = pq.remove();
			pass += now.c;
			for(int i=0;i<days && pBug<m;i++,pBug++)
				ans[bug[pBug].idx] = now.idx;
		}
		
		return pass <= s;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}

class Bug implements Comparable<Bug>{
	int a,idx;
	Bug(int i,int a){
		this.a = a;
		this.idx = i;
	}
	public int compareTo(Bug o){
		return Integer.compare(o.a, a);
	}
	public String toString(){
		return idx + " " + a + " ";
	}
}

class Student implements Comparable<Student>{
	int b,c,idx;
	Student(int i){
		idx = i;
	}
	public int compareTo(Student o){
		return Integer.compare(o.b, b);
	}
	public String toString(){
		return idx + " " + b + " " + c + " ";
	}
}

class StudentComparator implements Comparator<Student>{
	public int compare(Student a, Student b) {
		if(a.c < b.c)	return -1;
		if(a.c > b.c)	return 1;
		if(a.b > b.b)	return -1;
		if(a.b < b.b)	return 1;
		return 0;
	}
}