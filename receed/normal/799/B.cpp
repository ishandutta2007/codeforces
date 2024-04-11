#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>p(n),a(n),b(n);
    for(int i = 0;i<n;i++)
        cin>>p[i];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    for(int i = 0;i<n;i++)
        cin>>b[i];
    vector<vector<int > >c(4);
    for(int i = 0;i<n;i++){
        for(int j=1;j<4;j++){
            if(a[i]==j || b[i]==j)
                c[j].push_back(-p[i]);
        }
    }
    set<int>us;
    for(int i =1;i<4;i++)
        sort(c[i].begin(),c[i].end());
    int k,t;
    cin>>k;
    for(int i =0;i<k;i++){
        cin>>t;
        while(c[t].size()>0 && us.count(c[t].back())>0){
            c[t].pop_back();
        }
        if(c[t].size()==0)
            cout<<"-1 ";
        else{
            cout<<-c[t].back()<<' ';
            us.insert(c[t].back());
        }
    }
    return 0;
}