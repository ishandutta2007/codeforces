 #include <bits/stdc++.h>
 int edges[1000000][2];
    using namespace std;
    int main()
    {
        int n;
        cin>>n;
        if (n%2==0)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            int edge=1;
            int node=3;
            edges[0][0]=1;
            edges[0][1]=2;
            for (int i=0;i<n-1;i++)
            {
                edges[edge][0]=node;
                edges[edge][1]=2;
                node++;
                edge++;
            }
            int x=node-1;
            int last=-1;
            for (int i=0;i<n-1;i++)
            {
                for (int j=3;j<=x;j++)
                {
                    edges[edge][0]=node;
                    edges[edge][1]=j;
                    edge++;
                }
                if (last!=-1 && i%2!=0)
                {
                    edges[edge][0]=last;
                    edges[edge][1]=node;
                    edge++;
                }
                node++;
                last=node-1;
            }
            int st=node;
            for (int i=0;i<n-1;i++)
            {
                edges[edge][0]=node;
                edges[edge][1]=1;
                node++;
                edge++;
            }
            x=node-1;
            last=-1;
            for (int i=0;i<n-1;i++)
            {
                for (int j=st;j<=x;j++)
                {
                    edges[edge][0]=node;
                    edges[edge][1]=j;
                    edge++;
                }
                if (last!=-1 && i%2!=0)
                {
                    edges[edge][0]=last;
                    edges[edge][1]=node;
                    edge++;
                }
                node++;
                last=node-1;
            }
            cout<<node-1<<" "<<edge<<endl;
            for (int i=0;i<edge;i++)
            {
               cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
            }
        }
    }