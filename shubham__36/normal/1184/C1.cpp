    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define v vector<ll> 
    #define vv vector<v>
    #define p pair<ll,ll>
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin>>n;
        vector<p> arr(4*n+2);
        for(int i=1; i<=4*n+1; i++)
        {
        	cin>>arr[i].first>>arr[i].second;
        }     
        for (int i=0; i<=50; i++)
        {
        	for (int j=0; j<=50; j++)
        	{
        		for (int k=1; k<=50; k++)
        		{
      		    		vector<int> temp;
     
    	    		for (int l=1; l<=4*n+1; l++)
    	    		{
    	    			int x=arr[l].first-i;
    	    			int y=arr[l].second-j;
    	    			if (x==0 && y<=k && y>=0)
    	    				continue;
    	    			if (x==k && y<=k && y>=0)
    	    				continue;
    	    			if (y==0 && x<=k && x>=0)
    	    				continue;
    	    			if (y==k && x<=k && x>=0)
    	    				continue;
    	    			temp.push_back(l);
    	    		}
    	    		if (temp.size()==1)
    	    		{
    	    			cout<<arr[temp[0]].first<<" "<<arr[temp[0]].second<<endl;
    	    			return 0;
    	    		}
    	    	}	
        	}
        }
        return 0;
    }