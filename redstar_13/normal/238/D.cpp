#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

typedef pair<pii,int> pi3;

#define NN 100010

#define MM 3000010

#define KK 10

char s[NN];

int pre[NN],nxt[NN];

int id[MM],ans[MM];

int fir[NN];

int sum[MM][KK];

vector<int> v[NN];

pi3 qur[NN];

int L[NN],R[NN];

vector<int> vct[MM];

vector<pii> vec[NN];

int res[NN];



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

    

	int n,q;

    scanf("%d%d",&n,&q);

    scanf("%s",s+1);

    for(int i=1;i<=n;i++){

        pre[i]=i-1;

        nxt[i]=i+1;

    }

    int st=1,vt=1,ct=0,sT=0,End=0,sta=1;

    while(true){

        ct++;

        ans[ct]=-1;

        id[ct]=st;

        if(st>n) break;

        if(st<sta){

            if(End<n){

                st=End+1;

                sta=End+1;

                vt=1;

                End++;

                continue;

            }

            else break;

        }

        End=max(End,st);

        if(s[st]=='>'||s[st]=='<'){

            if(s[st]=='>'){

                vt=1;

                sT=nxt[st];

                if(s[sT]=='>'||s[sT]=='<'){

                    pre[sT]=pre[st];

                    nxt[pre[st]]=sT;

                }

                st=sT;

            }

            else{

                vt=-1;

                sT=pre[st];

                if(s[sT]=='>'||s[sT]=='<'){

                    nxt[sT]=nxt[st];

                    pre[nxt[st]]=sT;

                }

//                if(sT<st-1){

//                    ct++;

//                    ans[ct]=-1;

//                    id[ct]=st-1;

//                }

                st=sT;

            }

        }

        else{

            int x=s[st]-'0';

            ans[ct]=x;

            if(x) s[st]='0'+x-1;

            else{

                nxt[pre[st]]=nxt[st];

                pre[nxt[st]]=pre[st];

            }

            if(vt>0) st=nxt[st];

            else{

//                if(pre[st]<st-1){

//                    ct++;

//                    ans[ct]=-1;

//                    id[ct]=st-1;

//                }

                st=pre[st];

            }

        }

    }

    

    for(int i=1;i<=ct;i++) vct[id[i]].push_back(i);

    for(int i=1;i<=ct;i++){

        for(int j=0;j<KK;j++){

            sum[i][j]=sum[i-1][j];

            if(ans[i]==j) sum[i][j]++;

        }

        v[id[i]].push_back(i);

        if(fir[id[i]]) continue;

        fir[id[i]]=i;

    }

    for(int i=1;i<=q;i++){

        scanf("%d%d",&L[i],&R[i]);

        int be=fir[L[i]];

        vec[L[i]-1].push_back(pii(be,i));

    }

    set<int> ss;

    ss.insert(ct+1);

    for(int i=0;i<=n+1;i++){

        for(int j=0;j<vct[i].size();j++) ss.insert(vct[i][j]);

        for(int j=0;j<vec[i].size();j++){

            int id=vec[i][j].second;

            int val=vec[i][j].first;

            res[id]=*ss.lower_bound(val);

        }

    }

    for(int i=1;i<=q;i++){

        int be=fir[L[i]],nd=ct;

        int Id=upper_bound(v[R[i]+1].begin(),v[R[i]+1].end(),be)-v[R[i]+1].begin();

        if(Id<v[R[i]+1].size()) nd=min(nd,v[R[i]+1][Id]-1);

        nd=min(nd,res[i]-1);

        for(int i=0;i<KK;i++) printf("%d ",sum[nd][i]-sum[be-1][i]);

        puts("");

    }

    return 0;

}