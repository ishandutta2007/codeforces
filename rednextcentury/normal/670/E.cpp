#include<bits/stdc++.h>
using namespace std;
#define ll long long
int nxt[1000000];
int prv[1000000];
int L[1000000];
int R[1000000];
bool del[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,p;
    cin>>n>>m>>p;
    string s;
    cin>>s;
    stack<int> st;
    s='.'+s;
    for (int i=1;i<s.size();i++){
        nxt[i]=i+1;
        prv[i]=i-1;
        if (i==0)prv[i]=-1;
        if (i+1==s.size())nxt[i]=-1;
        if (s[i]=='(')st.push(i);
        else {
            int x = st.top();
            R[x] = i;
            L[i] = x;
            st.pop();
        }
    }
    string q;
    cin>>q;
    int pos = p;
    for (auto x:q){
        if (x=='L'){
            pos = prv[pos];
        } else if (x=='R') {
            pos = nxt[pos];
        } else {
            int op;
            if (s[pos]=='('){
                op = R[pos];
                del[pos]=1;
                if (prv[pos]!=-1)
                    nxt[prv[pos]]=nxt[op];
                if (nxt[op]!=-1)
                    prv[nxt[op]]=prv[pos];

                if (nxt[op]==-1)pos=prv[pos];
                else pos=nxt[op];
            } else {
                op = L[pos];
                del[op]=1;
                if (prv[op]!=-1)
                    nxt[prv[op]]=nxt[pos];
                if (nxt[pos]!=-1)
                    prv[nxt[pos]]=prv[op];

                if (nxt[pos]==-1)pos=prv[op];
                else pos=nxt[pos];
            }
        }
    }
    string ret="";
    for (int i=1;i<s.size();)if (del[i]){
        i = R[i]+1;
    } else {
        ret+=s[i];
        i++;
    }
    cout<<ret<<endl;
}