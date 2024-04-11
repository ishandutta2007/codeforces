    #include<bits/stdc++.h>
    using namespace std;
    int aa[11][11],bel[11];
    vector<int> pt[1111];
    char mp[111][111][111];
    vector<int> eg[1111],egg[1111];
    int eggg[1111][1111];
    int in[11],dep[11];
    vector<int> dg[111];
    queue<int> q;
    int top=10;
    void addx(int xmin,int xmax,int y,int z)
    {
    	for(int i=xmin;i<=xmax;i++)
    		mp[i][y][z]='#';
    }
    void addy(int x,int ymin,int ymax,int z)
    {
    	for(int i=ymin;i<=ymax;i++)
    		mp[x][i][z]='#';
    }
    int main()
    {
    	int n;
    	ios_base::sync_with_stdio(false);
    	cin>>n;
    	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>aa[i][j];
    	//phase 1
    	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&aa[i][k]&&aa[k][j])aa[i][j]=1;
    	for(int i=1;i<=n;i++)
    	{
    		if(bel[i])
    		{
    			continue;
    		}
    		else
    		{
    			pt[i].push_back(i);
    			for(int j=i+1;j<=n;j++)
    				if(aa[i][j]&&aa[j][i])
    				{
    					pt[i].push_back(j);
    					bel[j]=i;
    				}
    		}
    	}
    	for(int t=1;t<=3;t++)
    		for(int i=1;i<=n;i++)
    			for(int j=1;j<=n;j++)
    				for(int k=1;k<=n;k++)
    					if(!bel[i]&&!bel[j]&&!bel[k]&&aa[i][j]&&aa[j][k])aa[i][k]=0;
    //	for(int i=1;i<=n;i++){cerr<<i<<":";for(auto x:pt[i])cerr<<x<<' ';cerr<<endl;}
    //	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cerr<<aa[i][j]<<' ';cerr<<endl;}
    	//phase 2
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=n;j++)
    		{
    			if(aa[i][j]&&!bel[i]&&!bel[j]&&i!=j)
    			{
    				eg[i].push_back(j);
    				in[j]++;
    			}
    		}
    	}
    	for(int i=1;i<=n;i++)
    	{
    		if(!bel[i]&&!in[i])
    		{
    			dep[i]=1;
    			q.push(i);
    		}
    	}
    	while(!q.empty())
    	{
    		int u=q.front();q.pop();
    		for(auto v:eg[u])
    		{
    			in[v]--;
    			dep[v]=max(dep[v],dep[u]+1);
    			if(in[v]==0)q.push(v);
    		}
    	}
    	/*
    	for(int i=1;i<=n;i++)
    	{
    		if(bel[i])continue;
    		cerr<<i<<"(dep = "<<dep[i]<<"):";
    		for(auto x:eg[i])cerr<<x<<' ';
    		cerr<<endl;
    	}//*/
    	//phase 3
    	for(int i=1;i<=n;i++)
    	{
    		if(bel[i])continue;
    		for(auto v:eg[i])
    		{
    			if(dep[v]==dep[i]+1)
    				egg[i].push_back(v),eggg[i][v]=1;
    			else
    			{
    				egg[i].push_back(++top),eggg[i][top]=1;
    				for(int w=dep[i]+1;w<dep[v]-1;w++)
    				{
    					int tmp=top;
    					dep[tmp]=w;
    					egg[tmp].push_back(++top),eggg[tmp][top]=1;
    				}
    				dep[top]=dep[v]-1;
    				egg[top].push_back(v),eggg[top][v]=1;
    			}
    		}
    	}
    	/*
    	for(int i=1;i<=top;i++)
    	{
    		if(bel[i])continue;
    		cerr<<i<<":";
    		for(auto x:egg[i])cerr<<x<<' ';
    		cerr<<endl;
    	}*/
    	//phase 4
    	int maxdep=0;
    	for(int i=1;i<=n;i++)if(!bel[i])maxdep=max(maxdep,dep[i]);
    //	cerr<<maxdep<<endl;
    	for(int i=1;i<=maxdep;i++)
    	{
    		for(int j=0;j<=30;j++)
    		{
    			if(i%2)addx(1,100,j*3+1,i*5+3),addx(1,100,j*3+1,i*5+2),addx(1,100,j*3+2,i*5+4),addx(1,100,j*3+3,i*5+3),addx(1,100,j*3+3,i*5+2);
    			else addy(j*3+1,1,100,i*5+3),addy(j*3+1,1,100,i*5+2),addy(j*3+2,1,100,i*5+4),addy(j*3+3,1,100,i*5+3),addy(j*3+3,1,100,i*5+2);
    		}
    	}
    	//phase 5
    	for(int i=1;i<=top;i++)
    	{
    		if(!bel[i])
    		{
    //			cerr<<"push "<<dep[i]<<' '<<i<<endl;
    			dg[dep[i]].push_back(i);
    		}
    	}
    	for(int i=1;i<=maxdep;i++)
    	{
    		for(int a=0;a<dg[i].size();a++)
    		{
    			int u=dg[i][a];
    			for(int o=0;o<pt[u].size();o++)
    			{
    				if(i%2)mp[o+1][a*3+2][i*5+3]=pt[u][o]+'0';
    				else mp[a*3+2][o+1][i*5+3]=pt[u][o]+'0';
    			}
    			for(int b=0;b<dg[i+1].size();b++)
    			{
    				int v=dg[i+1][b];
    				if(eggg[u][v])
    				{
    					if(i%2)
    						mp[b*3+2][a*3+1][i*5+3]=0;
    					else
    						mp[a*3+1][b*3+2][i*5+3]=0;
    				}
    			}
    		}
    	}
    	//output
    	//*
    	cout<<"100 100 100"<<endl;
    	for(int k=1;k<=100;k++)
    	{
    		for(int i=1;i<=100;i++)
    		{
    			for(int j=1;j<=100;j++)
    			{
    				cout<<(mp[i][j][k]==0?'.':mp[i][j][k]);
    			}
    			cout<<endl;
    		}
    		cout<<endl;
    	}
    	//*/
    	return 0;
    }