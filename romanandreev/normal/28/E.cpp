#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
typedef double ld;
typedef pair<ld,ld> pii;
typedef pair<pii,ld> line;
typedef vector<ld> vd;
typedef vector<vd> matrix;
vector<pii> ls;
pii p[100000];
int n;
pii p0;
ld vx,vy,vz,ux,uy,uz,Fd,anst1,anst2;
const ld eps=1e-10;
pii operator +(pii a,pii b){
    return mp(a.fs+b.fs,a.sc+b.sc);
}
pii operator -(pii a,pii b){
    return mp(a.fs-b.fs,a.sc-b.sc);
}
ld operator *(pii a,pii b){
    return a.fs*b.fs+a.sc*b.sc;
}
ld operator /(pii a,pii b){
    return a.fs*b.sc-a.sc*b.fs;
}

line make_l(pii a,pii b){
    line ll;
    ll.fs.fs=(b-a).sc;
    ll.fs.sc=(a-b).fs;
    ll.sc=-(ll.fs.fs*a.fs+ll.fs.sc*a.sc);
    return ll;
}
void make_p(line a,line b,pii p1,pii p2){
    ld dd=a.fs.fs*b.fs.sc-a.fs.sc*b.fs.fs;
    if (abs(dd)>eps){
        ld dx=a.sc*b.fs.sc-a.fs.sc*b.sc;
        ld dy=a.fs.fs*b.sc-a.sc*b.fs.fs;
        pii p0=mp(-dx/dd,-dy/dd);
        if ((abs((p1-p0)/(p2-p0))<eps)&&((p0-p1)*(p2-p1)>=-eps)&&((p0-p2)*(p1-p2)>=-eps))
            ls.pb(p0);
    }
}
line solve(matrix a){
    int n=a.size();
    int m=a[0].size()-1;
    /*cerr<<n<<" "<<m<<endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<=m;j++) cerr<<a[i][j]<<" ";
        cerr<<endl;
    }*/
    vector<int> ws(n,0);
    vector<int> pr(m,-1);
    vector<ld> gg(m,0);
    for (int k=0;k<n;k++){
        int mnx=-1;
        int mny=-1;
        for (int i=0;i<n;i++)if (ws[i]==0){
            for (int j=0;j<m;j++)if (abs(a[i][j])>eps){
                mnx=i;
                mny=j;
            }
        }
        if (mnx==-1) break;
        ld ff=a[mnx][mny];
        ws[mnx]=1;
        for (int i=0;i<=m;i++){
            a[mnx][i]/=ff;
        }
        pr[mny]=mnx;
        for (int i=0;i<n;i++) if (i!=mnx){
            ff=a[i][mny];
            for (int j=0;j<=m;j++){
                a[i][j]-=ff*a[mnx][j];
            }
        }
    }
    for (int i=0;i<n;i++) if (ws[i]==0){
        if (abs(a[i][m])>eps){
            return mp(mp(-1,-1),-1);
        }
    }
    /*for (int i=0;i<n;i++){
        for (int j=0;j<=m;j++) cerr<<a[i][j]<<" ";
        cerr<<endl;
    }*/
    for(int i=0;i<m;i++)
        if (pr[i]==-1)
            gg[i]=0;
        else {
            gg[i]=a[pr[i]][m];
        }
    for (int i=0;i<m;i++)
        if (gg[i]<-eps){
            return mp(mp(-1,-1),-1);
        }
    return mp(mp(gg[0],gg[1]),gg[2]);
}
void try_solve(pii p1){
    //cerr<<p1.fs<<" "<<p1.sc<<endl;
    matrix mt;
    vd vv;
    vv.pb(vx);vv.pb(0);vv.pb(ux);vv.pb(p1.fs-p0.fs);
    mt.pb(vv);
    vv.clear();
    vv.pb(vy);vv.pb(0);vv.pb(uy);vv.pb(p1.sc-p0.sc);
    mt.pb(vv);
    vv.clear();
    vv.pb(vz);vv.pb(Fd);vv.pb(uz);vv.pb(0);
    mt.pb(vv);
    line ans=solve(mt);
    if (ans.fs.fs>=-eps){
        if (ans.fs.fs<=anst1+eps){
            if ((ans.fs.fs<anst1-eps)||(ans.fs.sc<=anst2+eps)){
                anst1=ans.fs.fs;
                anst2=ans.fs.sc;
            }
        }
    }
    //cerr<<ans.fs.fs<<" "<<anst1<<" "<<anst2<<endl;
    vv.clear();
    vv.pb(0);vv.pb(1);vv.pb(0);vv.pb(0);
    mt.pb(vv);
    ans=solve(mt);
    if (ans.fs.fs>=-eps){
        if (ans.fs.fs<=anst1+eps){
            if ((ans.fs.fs<anst1-eps)||(ans.fs.sc<=anst2+eps)){
                anst1=ans.fs.fs;
                anst2=ans.fs.sc;
            }
        }
    }
    //cerr<<ans.fs.fs<<" "<<anst1<<" "<<anst2<<endl;
    mt[3][1]=0;
    mt[3][2]=1;
    ans=solve(mt);
    if (ans.fs.fs>=-eps){
        if (ans.fs.fs<=anst1+eps){
            if ((ans.fs.fs<anst1-eps)||(ans.fs.sc<=anst2+eps)){
                anst1=ans.fs.fs;
                anst2=ans.fs.sc;
            }
        }
    }
    //cerr<<ans.fs.fs<<" "<<ans.fs.sc<<" "<<ans.sc<<" "<<anst1<<" "<<anst2<<endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%lf%lf",&p[i].fs,&p[i].sc);
        ls.pb(p[i]);
    }
    p[n]=p[0];
    scanf("%lf%lf",&p0.fs,&p0.sc);
    scanf("%lf%lf%lf%lf%lf%lf%lf",&vx,&vy,&vz,&Fd,&ux,&uy,&uz);
    //cerr<<vx<<" "<<vy<<" "<<vz<<endl;
    if (vx*vx+vy*vy>eps){
        for (int i=0;i<n;i++)
        make_p(make_l(p0,p0+mp(vx,vy)),make_l(p[i],p[i+1]),p[i],p[i+1]);
    }
    ld tt=-vz/uz;
    ld vvx=vx+tt*ux;
    ld vvy=vy+tt*uy;
    if (vvx*vvx+vvy*vvy>eps){
        for (int i=0;i<n;i++)
        make_p(make_l(p0,p0+mp(vvx,vvy)),make_l(p[i],p[i+1]),p[i],p[i+1]);
    }
    anst1=1e100;
    anst2=1e100;
    try_solve(ls[1]);
    //cerr<<anst1<<" "<<anst2<<endl;
    //return 0;
    for (int i=0;i<ls.size();i++){
        try_solve(ls[i]);
    }
    cout.precision(15);
    if (anst1>1e99)
        cout<<"-1 -1 "<<endl;
    else
        cout<<fixed<<anst1<<" "<<anst2<<endl;
}