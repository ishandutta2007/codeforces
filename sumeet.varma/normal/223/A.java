import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Stack;

public class R138qCBracketSequence {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    char s[] = br.readLine().toCharArray();
	    Stack<Character> s1 = new Stack<Character>();
	    Stack<Integer> s2 = new Stack<Integer>();
	    int n = s.length,lastUn = -1,ans = 0,ansRight = 0,ansLeft = 0;
	    
	    int count[] = new int[n];
	    count[0] = s[0] == '[' ? 1 : 0;
	    for(int i=1;i<n;i++)
	    	count[i] = count[i-1] + (s[i] == '[' ? 1 : 0);
	    
	    for(int i=0;i<n;i++){
	    	if(s[i] == '('){
	    		s1.push('(');
	    		s2.push(i);
	    	}
	    	else if(s[i] == '['){
	    		s1.push('[');
	    		s2.push(i);
	    	}
	    	else if(s[i] == ')'){
	    		if(s1.isEmpty())
	    			lastUn = i;
	    		else{
	    			if(s1.peek() == '('){
	    				s1.pop();
	    				s2.pop();
	    			}
	    			else{
	    				lastUn = i;
	    				s1.clear();
	    				s2.clear();
	    			}
	    		}
	    	}
	    	else{
	    		if(s1.isEmpty())
	    			lastUn = i;
	    		else{
	    			if(s1.peek() == '['){
	    				s1.pop();
	    				s2.pop();
	    			}
	    			else{
	    				lastUn = i;
	    				s1.clear();
	    				s2.clear();
	    			}
	    		}
	    	}
	    	
	    	int t = s2.isEmpty() ? -1 : s2.peek();
	    	int left = Math.max(lastUn, t);
	    	int der = count[i] - (left >= 0 ? count[left] : 0);
	    	
	    	if(der > ans){
	    		ans = der;
	    		ansLeft = left;
	    		ansRight = i;
	    	}
	    }
	    
	    w.println(ans);
	    for(int i=ansLeft+1;i<=ansRight;i++)
	    	w.print(s[i]);
	    w.println();
	   
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}