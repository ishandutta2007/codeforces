    #include<bits/stdc++.h>
    #define int long long
    #define pii pair<int,int>
    #define mp make_pair
    #define fi first
    #define se second
    #define R register
    #define I inline
     
    using namespace std;
     
    const int N=1e5+5;
    const int inf=0x3f3f3f3f3f3f3f3f;
    const int mod=1e9+7;
    const int mod2=998244353;
     
    I int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}}
     
    int n,l;
    double ans;
    int pos[N];
    double T1[N],T2[N];
    int V1[N],V2[N];
    string str;
    map<int,int> Map;
    vector<int> vec[N];
     
    void add(int u,int v){vec[u].push_back(v);vec[v].push_back(u);}
     
     
     
     
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		cin>>n>>l;
    		for (int i=1;i<=n;i++) cin>>pos[i];
    //		cout<<"endread"<<endl;
    		V1[0]=V2[n+1]=1;
    		T1[0]=T2[n+1]=0;
    		pos[0]=0;
    		pos[n+1]=l;
    		for (int i=1;i<=n+1;i++)
    		{
    			V1[i]=V1[i-1]+1;
    			T1[i]=T1[i-1]+(pos[i]-pos[i-1])/(V1[i-1]+0.0);
    			
    		}
    		for (int i=n;i>=0;i--)
    		{
    			V2[i]=V2[i+1]+1;
    			T2[i]=T2[i+1]+(pos[i+1]-pos[i])/(V2[i+1]+0.0);
    			
    		}
    //		cout<<"endinit"<<endl;
    //		for (int i=0;i<=n+1;i++) printf("%.6lf ",T1[i]);printf("\n");
    //		for (int i=0;i<=n+1;i++) printf("%.6lf ",T2[i]);printf("\n");
    		for (int i=0;i<=n+1;i++)
    		{
    			if (T1[i]>T2[i])
    			{
    				double t1=T1[i-1],t2=T2[i];
    				if (t1<t2) printf("%.15lf\n",t2+(pos[i]-pos[i-1]-(t2-t1)*V1[i-1])/(V1[i-1]+V2[i]+0.0));
    				else printf("%.15lf\n",t1+(pos[i]-pos[i-1]-(t1-t2)*V2[i])/(V1[i-1]+V2[i]+0.0));
    				break;
    			}
    		}
    	}
    }