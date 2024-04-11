#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
typedef pair<ld,ld>pld;
const int inf=1e9+7;
const ll INF=1e18;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(18);
    int t,q;
    cin>>t>>q;
    vector<vector<ld> >v(t);
    vector<vector<ld> >p(t);
    ld sumnotouch=0;
    vector<ld>A(t),B(t),S(t);
    vector<ld>notouchv(t);
    priority_queue<pair<ld,int>,vector<pair<ld,int> >,greater<pair<ld,int> > >grpq;
    vector<priority_queue<pair<ld,int>,vector<pair<ld,int> >,greater<pair<ld,int> > > >velpq(t);
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        v[i].resize(n);
        p[i].resize(n);
        ld sumc=0,sump=0;
        for(ld&t:v[i])
        {
            ll t2;
            cin>>t2;
            t=t2;
            sumc+=t2;
        }
        for(ld&t:p[i])
        {
            ll t2;
            cin>>t2;
            t=t2;
            sump+=t2;
        }
        for(ld&t:p[i])
            t/=sump;
        auto&cut=velpq[i];
        ld coef=0,cons=0;
        for(int j=0;j<n;j++)
        {
            if(v[i][j]>p[i][j]*sumc)
            {
                cut.ep(v[i][j]/p[i][j],j);
                coef+=v[i][j],cons-=p[i][j];
            }
            else
                coef-=v[i][j],cons+=p[i][j];
        }
        coef+=sumc,cons-=1; // A and B can be changed
        A[i]=coef,B[i]=cons,S[i]=sumc;
        ld ifnotouch=A[i]/S[i]+B[i];
        sumnotouch+=ifnotouch;
        notouchv[i]=ifnotouch;
        grpq.ep(S[i]/sqrtl(A[i]),i);
    }
    ld sofS=0;
    ld sofsqA=0;
    ld sofB=0;
    int curgrp=0;
    priority_queue<pair<ld,int>,vector<pair<ld,int> >,greater<pair<ld,int> > >elpq; //cut if P'/sofsqA > LD then renew v[i][j] and p[i][j]
    vector<pair<ll,int> >vq(q);
    for(auto&t:vq)
        cin>>t.fi;
    for(int i=0;i<q;i++)
        vq[i].se=i;
    sort(all(vq));
    vector<ld>ans(q);
    for(auto&t:vq)
    {
        ld P=sofS+t.fi;
        ld Q=sofsqA;
        while(!grpq.empty()||!elpq.empty())
        {
            if(curgrp==0)
            {
                int id=grpq.top().se;
                grpq.pop();
                sumnotouch-=notouchv[id];
                sofS+=S[id];
                sofsqA+=sqrtl(A[id]);
                sofB+=B[id];
                if(!velpq[id].empty())
                    elpq.ep(velpq[id].top().fi/sqrtl(A[id]),id);
                curgrp++;
            }
            else if(grpq.empty())
            {
                if(elpq.top().fi>=P/Q)
                    break;
                int i=elpq.top().se;
                elpq.pop();
                int j=velpq[i].top().se;
                velpq[i].pop();
                S[i]=v[i][j]/p[i][j];
                sofS-=S[i];
                sofsqA-=sqrtl(A[i]);
                sofB-=B[i];
                A[i]-=2*v[i][j];
                B[i]+=2*p[i][j];
                notouchv[i]=A[i]/S[i]+B[i];
                sumnotouch+=notouchv[i];
                grpq.ep(S[i]/sqrtl(A[i]),i);
                curgrp--;
            }
            else if(elpq.empty())
            {
                if(grpq.top().fi>=P/Q)
                    break;
                int id=grpq.top().se;
                grpq.pop();
                sumnotouch-=notouchv[id];
                sofS+=S[id];
                sofsqA+=sqrtl(A[id]);
                sofB+=B[id];
                if(!velpq[id].empty())
                    elpq.ep(velpq[id].top().fi/sqrtl(A[id]),id);
                curgrp++;
            }
            else if(elpq.top()<grpq.top())
            {
                if(elpq.top().fi>=P/Q)
                    break;
                int i=elpq.top().se;
                elpq.pop();
                int j=velpq[i].top().se;
                velpq[i].pop();
                S[i]=v[i][j]/p[i][j];
                sofS-=S[i];
                sofsqA-=sqrtl(A[i]);
                sofB-=B[i];
                A[i]-=2*v[i][j];
                B[i]+=2*p[i][j];
                notouchv[i]=A[i]/S[i]+B[i];
                sumnotouch+=notouchv[i];
                grpq.ep(S[i]/sqrtl(A[i]),i);
                curgrp--;
            }
            else
            {
                if(grpq.top().fi>=P/Q)
                    break;
                int id=grpq.top().se;
                grpq.pop();
                sumnotouch-=notouchv[id];
                sofS+=S[id];
                sofsqA+=sqrtl(A[id]);
                sofB+=B[id];
                if(!velpq[id].empty())
                    elpq.ep(velpq[id].top().fi/sqrtl(A[id]),id);
                curgrp++;
            }
            P=sofS+t.fi;
            Q=sofsqA;
        }
        ans[t.se]=sumnotouch+(sofB+Q*Q/P);
    }
    for(ld&t:ans)
        cout<<t<<'\n'; 
    return 0;
}