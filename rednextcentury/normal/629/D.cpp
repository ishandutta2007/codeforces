#include <bits/stdc++.h>

using namespace std;

long long Segment[6000005];
long long dp[2000005],Ans,b[200005];
long long index,n,a[200005],Max;

map<long long,int>mymap;

void Build(int node,int Start,int End){
    if(Start==End)
    {

        Segment[node]=dp[Start];

        return;

    }

    int mid=(Start+End)/2;

    Build(2*node,Start,mid);

    Build(2*node+1,mid+1,End);

    Segment[node]=max(Segment[2*node],Segment[2*node+1]);

}
void Update(int node,int Start,int End,int index,double value){
    if(Start==End){

        Segment[node]=value;

        return ;
    }
    int mid=(Start+End)/2;

    if(Start <= index && index<= mid)

        Update(2*node,Start,mid,index,value);

    else

        Update(2*node+1,mid+1,End,index,value);

    Segment[node]=max(Segment[2*node],Segment[2*node+1]);

}
long long Query(int node,int Start,int End,int Left,int Right){
    if(Start > Right|| End < Left)

        return 0.0;

    if(Left <= Start && End <= Right)

        return Segment[node];

    int mid=(Start+End)/2;

    long long Ans1=Query(2*node,Start,mid,Left,Right);

    long long Ans2=Query(2*node+1,mid+1,End,Left,Right);

    return max(Ans1,Ans2);

}


int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        long long r,v;
        scanf("%I64d%I64d",&r,&v);

        a[i]=r*v*r;
        b[i]=a[i];
    }



    for(int i=0; i<n; i++)  mymap[a[i]]++;

    for(auto it=mymap.begin(); it!= mymap.end(); it++)  it->second=index++;

    for(int i=0; i<n; i++){

        a[i]=mymap[a[i]];

        Max=max(Max,a[i]);
    }


    for(int i=n-1; i>=0; i--){

        dp[a[i]]=max(dp[a[i]],b[i]+Query(1,1,1e6,a[i]+1,Max));

        Update(1,1,1e6,a[i],dp[a[i]]);


        Ans=max(Ans,dp[a[i]]);
    }

    cout<<setprecision(9)<<fixed<<(double)Ans*acos(-1)<<endl;
    return 0;
}