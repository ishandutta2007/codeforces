import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class TaskB {

	public static void main(String args[] ) throws Exception {
		
		//65 = System.out.println((int)'A');
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		char s[] = br.readLine().toCharArray();
		char t[] = br.readLine().toCharArray();
	         
		int hd = 0;
		int hash[][] = new int[26][26];
		for(int i=0;i<26;i++)
			Arrays.fill(hash[i],-1);
		
		for(int i=0;i<n;i++){
			if(s[i] != t[i]){
				hd++;
				hash[s[i] - 'a'][t[i]-'a'] = i;
			}
		}
	    
		boolean found1 = false;
		boolean found2 = false;
		int i1 = -1,i2 = -1;
		
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				if(hash[i][j]!=-1){
					if(hash[j][i] != -1){
						i1 = hash[i][j] + 1;
						i2 = hash[j][i] + 1;
						found2 = true;
					}
				}
			}
		}
		
		if(!found2){
			for(int i=0;i<26;i++){
				for(int j=0;j<26;j++){
					if(hash[i][j] !=-1){
						for(int k=0;k<26;k++){
							if(k!=i && hash[k][i]!=-1){
								found1 = true;
								i1 = hash[i][j] + 1;
								i2 = hash[k][i] + 1;
							}
						}
					}
				}
			}
		}
	    if(found2)
	    	hd -=2;
	    else if(found1)
	    	hd -=1;
	    
	    w.println(hd);
	    w.println(i1 + " " + i2);
		w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}