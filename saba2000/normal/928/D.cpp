#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define fr first
#define sc second
#define pb push_back
#define ARRS ((ll)(5e6+100))
#define MAX ((ll)(3e17+100))
#define MX ((ll)(2e9+100))

struct node{
    node *w[30];
    ll s;
    ll x;
    node(){
        x=0;
        for(int i=0; i<30; i++)w[i]=NULL;
    }
    void updt(){
        s=x;
        for(int i=0; i<30; i++)
            if(w[i])s+=w[i]->s;
    }
};

ll wi;
string wts;
ll ms,mex;

void ins(node *&x){
    if(!x)x=new node();
   // if(wi==0)x->x=1;
    if(wi==wts.size()){x->x=1;x->updt();return;}
    ins(x->w[wts[wi++]-'a']);
    x->updt();
}

void gret(node *& x){
    if(!x)return;
   // cout<<wts<<" "<<wi<<" "<<x->x<<" "<<x->s<<endl;
    if(ms==MAX&&x->s==1)ms=wi;
    if(x->s==1&&x->x==1)mex=wi;
    if(wi==wts.size())return;
    gret(x->w[wts[wi++]-'a']);
}

node *root;

int main(){
    ios::sync_with_stdio(0);
    #ifdef KHOKHO
        freopen("in.in","r",stdin);
        freopen("out.out","w+",stdout);
    #endif // KHOKHO

    root=NULL;
    string s;
    wts="";
    wi=0;
    ins(root);
    vector<string> v;
    while(getline(cin,s)){
        if(s=="")break;
        string k="";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='.'||s[i]==','||s[i]=='?'||s[i]=='!'||s[i]=='\''||s[i]=='-'||s[i]==' '){
                if(k!=""){
                    v.pb(k);
                    k="";
                }
                v.pb("");
            }
            else k+=s[i];
        }
        if(k!=""){
            v.pb(k);
            k="";
        }
        v.pb("");
    }

    //v.pop_back();

    ll pas=0;
    for(auto tu:v){
      //  cout<<tu<<endl;
        if(tu==""){pas++;continue;}
        wts=tu;

        mex=-MAX;
        ms=MAX;

        wi=0;
        gret(root);
        ms++;
       // cout<<wts.size()<<" "<<(-mex+ms)<<endl;
        pas+=min((ll)wts.size(),(ll)wts.size()-mex+ms);

        //cout<<"("<<tu<<")"<<" "<<mex<<" "<<ms<<" "<<pas<<" - "<<min((ll)wts.size(),(ll)wts.size()-mex+ms)<<endl;
        wi=0;
        ins(root);
    }

    cout<<pas;
}