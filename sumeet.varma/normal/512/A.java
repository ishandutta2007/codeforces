import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;


public class FoxAndNames {

	static ArrayList<Integer> g[] ;
	static int in[];
	static int ad[][] ;
	
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	  
	    ad = new int[26][26];
	    in = new int[26];
	    g = new ArrayList[26];
	    for(int i=0;i<26;i++)
	    	g[i] = new ArrayList();
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    String left = br.readLine().trim();
	    for(int i=1;i<n;i++){
	    	String right = br.readLine().trim();
	    	int min = Math.min(left.length(), right.length());
	    	char l[] = left.toCharArray();
	    	char r[] = right.toCharArray();
	    	boolean found = false;
	    	for(int j=0;j<min;j++){
	    		if(l[j] != r[j]){
	    			g[l[j]-'a'].add(r[j]-'a');
	    			ad[l[j]-'a'][r[j]-'a'] = 1;
	    			in[r[j]-'a']++;
	    			found = true;
	    			break;
	    		}
	    		
	    	}
	    	
	    	if(!found && l.length > r.length){
	    		System.out.println("Impossible");
	    		return;
	    	}
	    	left = right;
	    }
	       
	    
	    
	    LinkedList<Integer> q = new LinkedList();
	    for(int i=0;i<26;i++){
	    	if(in[i] == 0){
	    		
	    		q.add(i);
	    	}
	    }
	    
	    
	    StringBuilder buf = new StringBuilder("");
	   boolean visited[] = new boolean[26];
	    
	    while(!q.isEmpty()){
	    	int curr = q.remove();
	    	if(visited[curr] == true){
	    		System.out.println("Impossible");
	    		return;
	    	}
	    	visited[curr] = true;
	    	buf.append((char)(curr+'a'));
	    	
	    	int len = g[curr].size();
	    	for(int i=0;i<len;i++){
	    		in[g[curr].get(i)]--;
	    		if(in[g[curr].get(i)] == 0)
	    			q.add(g[curr].get(i));
	    	}
	    }
	    	
	    for(int i=0;i<26;i++){
	    	if(visited[i] == false){
	    		System.out.println("Impossible");
	    		return;
	    	}
	    		
	    }
	    
	    w.println(buf);
	    	
	    w.println();
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}

class CheckCycle

{

    private Stack<Integer> stack;

    private int adjacencyMatrix[][];

 

    public CheckCycle() 

    {

        stack = new Stack<Integer>();

    }

 

    public boolean dfs(int adjacency_matrix[][], int source)

    {

        int number_of_nodes = adjacency_matrix[source].length - 1;

 

        adjacencyMatrix = new int[number_of_nodes + 1][number_of_nodes + 1];

        for (int sourcevertex = 1; sourcevertex <= number_of_nodes; sourcevertex++)

        {
          for (int destinationvertex = 1; destinationvertex <= number_of_nodes; destinationvertex++)

            {

                adjacencyMatrix[sourcevertex][destinationvertex] =

                   adjacency_matrix[sourcevertex][destinationvertex];

            }
      }



        int visited[] = new int[number_of_nodes + 1];		

        int element = source;		

        int destination = source;			

        visited[source] = 1;		

        stack.push(source);



        while (!stack.isEmpty())

        {

            element = stack.peek();

            destination = element;	
	    while (destination <= number_of_nodes)

    {

               if (adjacencyMatrix[element][destination] == 1 && visited[destination] == 1)

               {

                  if (stack.contains(destination))

                   {	

                       

                       return true;	

                    }

                }



              	if (adjacencyMatrix[element][destination] == 1 && visited[destination] == 0)

        {
                   stack.push(destination);

                   visited[destination] = 1;

                   adjacencyMatrix[element][destination] = 0;

                    element = destination;

                   destination = 1;

	            continue;

               }

                destination++;

    }

            stack.pop();	

      }	

        return false;
    }
}