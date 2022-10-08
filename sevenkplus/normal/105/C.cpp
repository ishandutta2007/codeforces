#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
map<string,pair<pair<int,int>,vector<string> > >ai;map<string,pair<int,string> >ar;
map<string,int> ti,tr;
vector<string> atki,defi,resi;
vector<string> atkr,defr,resr;
set<string> v;
int n,m,sz;
bool cmp(const string&a,const string&b)
{
    return ar[a].fi>ar[b].fi;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string nam,cla;int atk,def,res,siz;
        cin>>nam>>cla>>atk>>def>>res>>siz;
        if(cla=="weapon")ai[nam].fi=mp(atk,siz),atki.pb(nam),ti[nam]=1;else
        if(cla=="armor")ai[nam].fi=mp(def,siz),defi.pb(nam),ti[nam]=2;else
        if(cla=="orb")ai[nam].fi=mp(res,siz),resi.pb(nam),ti[nam]=3;
        sz+=siz;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string nam,cla;int num;string hom;
        cin>>nam>>cla>>num>>hom;
        if(cla=="gladiator")ar[nam]=mp(num,hom),atkr.pb(nam),ai[hom].se.pb(nam),tr[nam]=1;else
        if(cla=="sentry")ar[nam]=mp(num,hom),defr.pb(nam),ai[hom].se.pb(nam),tr[nam]=2;else
        if(cla=="physician")ar[nam]=mp(num,hom),resr.pb(nam),ai[hom].se.pb(nam),tr[nam]=3;
    }
    sort(atkr.begin(),atkr.end(),cmp),
    sort(defr.begin(),defr.end(),cmp),
    sort(resr.begin(),resr.end(),cmp);
    int atks=-1,defs=-1,ress=-1;string atkn,defn,resn;
    if(sz==m)
    {
        for(int i=0;i<(int)atki.size();i++)
        {
            int a=ai[atki[i]].fi.fi;
            for(int j=0;j<(int)ai[atki[i]].se.size();j++)
                if(ti[atki[i]]==tr[ai[atki[i]].se[j]])a+=ar[ai[atki[i]].se[j]].fi;
            if(a>atks)atks=a,atkn=atki[i];
        }
        for(int i=0;i<(int)defi.size();i++)
        {
            int a=ai[defi[i]].fi.fi;
            for(int j=0;j<(int)ai[defi[i]].se.size();j++)
                if(ti[defi[i]]==tr[ai[defi[i]].se[j]])a+=ar[ai[defi[i]].se[j]].fi;
            if(a>defs)defs=a,defn=defi[i];
        }
        for(int i=0;i<(int)resi.size();i++)
        {
            int a=ai[resi[i]].fi.fi;
            for(int j=0;j<(int)ai[resi[i]].se.size();j++)
                if(ti[resi[i]]==tr[ai[resi[i]].se[j]])a+=ar[ai[resi[i]].se[j]].fi;
            if(a>ress)ress=a,resn=resi[i];
        }
        cout<<atkn<<" "<<(int)ai[atkn].se.size();
        for(int i=0;i<(int)ai[atkn].se.size();i++)
            cout<<" "<<ai[atkn].se[i];
        cout<<endl;
        cout<<defn<<" "<<(int)ai[defn].se.size();
        for(int i=0;i<(int)ai[defn].se.size();i++)
            cout<<" "<<ai[defn].se[i];
        cout<<endl;
        cout<<resn<<" "<<(int)ai[resn].se.size();
        for(int i=0;i<(int)ai[resn].se.size();i++)
            cout<<" "<<ai[resn].se[i];
        cout<<endl;
        return 0;
    }
    for(int i=0;i<(int)atki.size();i++)
    {
        int a=ai[atki[i]].fi.fi;
        for(int j=0;j<min((int)atkr.size(),ai[atki[i]].fi.se);j++)
            a+=ar[atkr[j]].fi;
        if(a>atks)atks=a,atkn=atki[i];
    }
    for(int i=0;i<(int)defi.size();i++)
    {
        int a=ai[defi[i]].fi.fi;
        for(int j=0;j<min((int)defr.size(),ai[defi[i]].fi.se);j++)
            a+=ar[defr[j]].fi;
        if(a>defs)defs=a,defn=defi[i];
    }
    for(int i=0;i<(int)resi.size();i++)
    {
        int a=ai[resi[i]].fi.fi;
        for(int j=0;j<min((int)resr.size(),ai[resi[i]].fi.se);j++)
            a+=ar[resr[j]].fi;
        if(a>ress)ress=a,resn=resi[i];
    }
    ai[atkn].se.clear();
    for(int i=0;i<min((int)atkr.size(),ai[atkn].fi.se);i++)
        ai[atkn].se.pb(atkr[i]),v.insert(atkr[i]);
    ai[defn].se.clear();
    for(int i=0;i<min((int)defr.size(),ai[defn].fi.se);i++)
        ai[defn].se.pb(defr[i]),v.insert(defr[i]);
    ai[resn].se.clear();
    for(int i=0;i<min((int)resr.size(),ai[resn].fi.se);i++)
        ai[resn].se.pb(resr[i]),v.insert(resr[i]);
    for(map<string,pair<int,string> >::iterator i=ar.begin();i!=ar.end();i++)
        if(v.find(i->fi)==v.end())
        {
            v.insert(i->fi);
            if(ai[atkn].fi.se>(int)ai[atkn].se.size()){ai[atkn].se.pb(i->fi);continue;}
            if(ai[defn].fi.se>(int)ai[defn].se.size()){ai[defn].se.pb(i->fi);continue;}
            if(ai[resn].fi.se>(int)ai[resn].se.size()){ai[resn].se.pb(i->fi);continue;}
        }
    cout<<atkn<<" "<<(int)ai[atkn].se.size();
    for(int i=0;i<(int)ai[atkn].se.size();i++)
        cout<<" "<<ai[atkn].se[i];
    cout<<endl;
    cout<<defn<<" "<<(int)ai[defn].se.size();
    for(int i=0;i<(int)ai[defn].se.size();i++)
        cout<<" "<<ai[defn].se[i];
    cout<<endl;
    cout<<resn<<" "<<(int)ai[resn].se.size();
    for(int i=0;i<(int)ai[resn].se.size();i++)
        cout<<" "<<ai[resn].se[i];
    cout<<endl;
    return 0;
}