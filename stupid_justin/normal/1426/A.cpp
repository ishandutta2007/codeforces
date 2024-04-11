    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    	int T,n,x;
    	cin>>T;
    	while (T--)
    	{
    		cin>>n>>x;
    		if (n<=2) cout<<1<<endl;
    		else cout<<(n-2+x-1)/x+1<<endl;
    	}
    }