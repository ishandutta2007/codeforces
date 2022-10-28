//package GoodBye2013;

import java.io.*;
import java.util.*;

public class GoodByeqDNewYearLetter {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter w = new PrintWriter(System.out);
		
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int k = ip(st1.nextToken());
		long x = ip(st1.nextToken());
	    int N = ip(st1.nextToken());
	    int M = ip(st1.nextToken());
	    
	    long s1[] = new long[k+1];
	    s1[1] = 1;	s1[2] = 0;
	    for(int i=3;i<=k;i++)
	    	s1[i] = s1[i-2] + s1[i-1];
	    
	    long s2[] = new long[k+1];
	    s2[1] = 0;	s2[2] = 1;
	    for(int i=3;i<=k;i++)
	    	s2[i] = s2[i-2] + s2[i-1];
	    
	    
	    long S12[] = new long[k+1];
	    S12[3] = 1;
	    for(int i=4;i<=k;i++)
	    	S12[i] = S12[i-1] + S12[i-2];
	    
	    long S22[] = new long[k+1];
	    for(int i=5;i<=k;i++){
	    	S22[i] = S22[i-1] + S22[i-2];
	    	if(i % 2 == 1)
	    		S22[i]++;
	    }
	    
	    long S21[] = new long[k+1];
	    for(int i=4;i<=k;i++){
	    	S21[i] = S21[i-1] + S21[i-2];
	    	if(i % 2 == 0)
	    		S21[i]++;
	    }
	    
	   	char ans1[] = new char[N];
	   	char ans2[] = new char[M];
	   	int n = N,m = M;
	   	
	   	for(int AC2 = 0;2*AC2 <= M;AC2++){
	   		for(int s22=0;s22<=1;s22++){
	   			for(int s21=0;s21<=1;s21++){
	   				for(int s12=0;s12<=1;s12++){
	   					Arrays.fill(ans1,'X');
	   					Arrays.fill(ans2,'X');
	   					if(s22 == 1){
	   						ans2[m-1] = 'A';
	   						ans2[0] = 'C';
	   					}
	   					if(s21 == 1){
	   						ans2[m-1] = 'A';
	   						ans1[0] = 'C';
	   					}
	   					if(s12 == 1){
	   						ans1[n-1] = 'A';
	   						ans2[0] = 'C';
	   					}
	   					if(s22 == 1){
	   						if(ans2[m-1] != 'A')
	   							continue;
	   						if(ans2[0] != 'C')
	   							continue;
	   					}
	   					if(s21 == 1){
	   						if(ans2[m-1] != 'A')	continue;
	   						if(ans1[0] != 'C')	continue;
	   					}
	   					if(s12 == 1){
	   						if(ans1[n-1] != 'A')	continue;
	   						if(ans2[0] != 'C')	continue;
	   					}
	   					
	   					int c = AC2;
	   					for(int i=0;i<m-1 && c>0;i++){
	   						if(ans2[i] == 'X' && ans2[i+1] == 'X'){
	   							ans2[i] = 'A';
	   							ans2[i+1] = 'C';
	   							c--;
	   						}
	   					}
	   					if(c != 0)
	   						continue;
	   					long done = AC2 * s2[k] + s22 * S22[k] + s21 * S21[k] + s12 * S12[k];
	   					long left = x - done;
	   					if(left >= 0 && left % s1[k] == 0){
	   						int t = (int)(left/s1[k]);
	   						for(int i=0;i<n-1 && t > 0;i++){
	   							if(ans1[i] == 'X' && ans1[i+1] == 'X'){
	   								ans1[i] = 'A';
	   								ans1[i+1] = 'C';
	   								t--;
	   							}
	   						}
	   						if(t == 0){
	   							w.println(new String(ans1));
	   							w.println(new String(ans2));
	   							w.close();
	   							return;
	   						}
	   					}
	   				}
	   			}
	   		}
	   	}
	    
	    
		System.out.println("Happy new year!");
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	
}