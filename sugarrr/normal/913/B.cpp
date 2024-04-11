

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
int mod(ll a){
    int c=a%1000000007;
    if(c>=0)return c;
    else return c+1000000007;
}
typedef pair<int,int> i_i;

int main(){
    int n;cin>>n;
    struct node{
        int parent;
        vector <int>child;
    };
    node p[n+1];
    for(int i=2;i<=n;i++){
        int q;cin>>q;
        p[q].child.push_back(i);
        p[i].parent=q;
    }
    int what[n+1];
    what[1]=1;
    for(int i=2;i<=n;i++){
        if(p[i].child.empty()==true)what[i]=2;
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(what[i]==2);
        else{
            int num=0;
            for(int j=0;j<=p[i].child.size()-1;j++){
                if(what[p[i].child[j]]==2)num++;
            }
            if(num<=2)flag=false;
        }
    }
    if(flag==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}