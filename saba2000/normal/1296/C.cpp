#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<pair<int,int>,int> M;
main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int n;cin>>n;
        cin >> s;
        M.clear();
        M[make_pair(0,0)] = 1;
        int x= 0,y=0;
        int l = 0, r= -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L') x++;
            if(s[i] == 'R') x--;
            if(s[i] == 'U') y++;
            if(s[i] == 'D') y--;
            if(M[make_pair(x,y)] == 0) {M[make_pair(x,y)] = i+2;continue;}
            if(i + 1 - M[make_pair(x,y)] < r - l || r== -1)
                l = M[make_pair(x,y)],  r= i + 1;
            M[make_pair(x,y)] = i+2;
        }
        if(r ==-1) cout<<-1<<endl;
        else cout<<l<<" "<<r<<endl;
    }

}