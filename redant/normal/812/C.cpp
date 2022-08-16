#include <bits/stdc++.h>
using namespace std;
long long arr[100005];
long long hh[100005];
int main() {
	int n;
	long long s;
	cin>>n>>s;
	long long a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	long long start=0;
	long long end=n;
	long long val;
	long long mid;
	long long max=0;
    long long min=0;
	while(start<=end)
	{
	    val=0;
	     mid=start+(end-start)/2;
	    for(int i=0;i<n;i++)
	    {
	        hh[i]=(a[i]+(i+1)*mid);
	    }
	    sort(hh,hh+n);
	    for(int i=0;i<mid;i++)
	    {
	        val+=hh[i];
	    }
	    if(val<=s)
	    {
	    max=mid;
        min=val;     
	    start=mid+1;
	    }
	    else
	    end=mid-1;
	 }
	cout<<max<<" "<<min<<endl;
	
    
	return 0;
}