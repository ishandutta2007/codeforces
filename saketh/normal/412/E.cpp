#include<iostream>
#include<vector>
#include<set>
using namespace std;

string inp;
vector<int> ats;
vector<int> dots;
int nlets[1000005];
int nnums[1000005];

int main(){
    cin >> inp;
    
    long long ans = 0;
    
    for(int i=0; i<inp.length(); i++){
        nnums[i+1] = nnums[i];
        nlets[i+1] = nlets[i];
        
        if(inp[i] == '.') dots.push_back(i);
        if(inp[i] == '@') ats.push_back(i);
        
        if('0' <= inp[i] && inp[i] <= '9')
            nnums[i+1]++;
        if('a' <= inp[i] && inp[i] <= 'z')
            nlets[i+1]++;
        
        if(dots.size() == 0) continue;
        int mydot = dots[dots.size()-1];
        if(mydot == i) continue;
        if(ats.size() == 0) continue;
        int myat = ats[ats.size()-1];
        if(myat >= mydot-1) continue;
        
        if(nlets[i+1] - nlets[mydot+1] != (i - mydot)) continue;
        if((nlets[mydot]-nlets[myat+1]+nnums[mydot]-nnums[myat+1])
            != (mydot - myat - 1)) continue;
        
        int stop = 0;
        if(dots.size() > 1) stop = max(stop, dots[dots.size()-2]+1);
        if(ats.size() > 1) stop = max(stop, ats[ats.size()-2]+1);
        
        ans += nlets[myat] - nlets[stop];
    }
    
    cout << ans << endl;
    
    return 0;
}