#include <bits/stdc++.h>
using namespace std;

vector<string> getsubstrings(string s){
    set<string> myset;
    for(int i=0;i<s.length();i++){
        for(int j=1;j+i<=s.length();j++){
            string aux = s.substr(i, j);
            myset.insert(aux);
        }
    }
    vector<string> ret;
    for(auto v:myset){
        ret.push_back(v);
    }
    return ret;
}

int main(void){
    int n;
    cin>>n;
    vector<string> myvector;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        myvector.push_back(s);
    }

    map<string, int> times;
    map<string, string> occur;
    for(int i=0;i<n;i++){
        string s = myvector[i];
            for(auto subs: getsubstrings(s)){
            times[subs]++;
            occur[subs]=s;
        }
    }

    //cout<<times.size()<<endl;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string aux;
        cin>>aux;
        cout<<times[aux]<<" ";
        if(times[aux]==0) cout<<"-\n";
        else cout<<occur[aux]<<"\n";
    }


    return 0;
}