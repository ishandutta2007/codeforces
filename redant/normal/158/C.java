
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bf.readLine());
        ArrayList<String> dirs = new ArrayList<String>();
        dirs.add("/");
        while(t-->0)
        {
            String s = bf.readLine().trim();
            if(s.length()==3)
            {
                for(String d : dirs) System.out.print(d);
                System.out.println("");
            }
            else
            {
                int i = dirs.size() - 1;
                String cd = s.split(" ")[1];
                if(cd.startsWith("/"))
                {
                    i = 0;
                    cd = cd.substring(1);
                    dirs.clear();
                    dirs.add("/");
                }
                String[] sa = cd.split("/");
                for(String d : sa)
                {
                    if(d.equals("..")) dirs.remove(i--);
                    else{ dirs.add(d+"/"); i++; }
                }
            }
        }
    }
}