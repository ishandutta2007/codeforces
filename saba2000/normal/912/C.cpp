#include<bits/stdc++.h>
using namespace std;
long long MH[200009],SH[200009],R[200009];
    vector<pair<long long,long long> > V[200009],l,L;
main()
{
    long long n,m;
    cin>>n>>m;
    long long B,I,D;
    cin >> B >> I >> D;
    for (long long i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld",& MH[i],& SH[i],&R[i]);
        if(MH[i] <= D && I!=0)
        {
            cout << -1 << endl;
            return 0;
        }}
    for (long long i=0; i< m ; i++)
    {
        long long t,e,h;
          scanf("%lld%lld%lld",&t,&e,&h);
        V[e].push_back({t,h});
        
    }
    long long ANS=0;
    for (long long i=1; i<= n; i++)
    {
            if(MH[i]<=D) {ANS++; continue;}
        sort (V[i].begin(), V[i].end());
        long long H=SH[i],T1=0;
        if(R[i]==0 && V[i].size())
            if(V[i][V[i].size()-1].second<=D && I!=0) {cout<<-1<<endl; return 0;}
             V[i].push_back({2e9,2e9});
        for (long long j=0; j < V[i].size(); j++)
        {

            long long T2=V[i][j].first;
            if(H>D) { T1=T2; H=V[i][j].second; continue;}
            if(H+(T2-T1)*R[i]<=D ) l.push_back({T1,T2-1}); else
            l.push_back({T1,T1+(D-H)/R[i]});
            T1=T2; H=V[i][j].second;
        }
    }
    for (long long i=0; i<l.size(); i++)
    {
        L.push_back({l[i].first,1});
        L.push_back({l[i].second+1,-1});
    }
    long long z=ANS;
    long long ans=ANS*B;
    sort(L.begin(),L.end());
    for (long long i=0; i<L.size(); i++)
    {
        if(L[i].second==1) z++;
        else
        {
            ans=max(ans,z*(B+I*(L[i].first-1)));
            z--;
        }

    }
    cout <<ans<<endl;
}