// In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxn = 2e5+20;
vector<int> Throw;
long long f[Maxn],s[Maxn];
long long ansx,ansy;
long long ans;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> f[i];
        Throw.push_back(f[i]);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m;i++){
        cin >> s[i];
        Throw.push_back(s[i]);
    }
    sort(f,f+n);
    sort(s,s+m);
    sort(Throw.begin(),Throw.end());
    if(n >= m){
        ans = 3*n-3*m;
        ansx = 3*n;
        ansy = 3*m;
    }else{
        ans = 2*n-2*m;
        ansx = 2*n;
        ansy = 2*m;
    }
    for(int i = 0; i < Throw.size();i++){
        long long tmpx=0,tmpy=0;
        int place = upper_bound(f,f+n,Throw[i])-f;
        tmpx = (place)*2 + (n-place)*3;
    //  cerr << "1:" << place << endl;
        place = upper_bound(s,s+m,Throw[i])-s;
        tmpy = (place)*2 + (m-place)*3;
    //  cerr << "2:" << place << endl;
        if(tmpx-tmpy >= ans){
            if(ans == tmpx-tmpy && tmpx > ansx){
                ansx = tmpx;
                ansy = tmpy;
            }else if(ans != tmpx-tmpy){
                ans = tmpx-tmpy;
                ansx = tmpx;
                ansy = tmpy;
            }
        }
    }
    cout << ansx << ":" << ansy << endl;
    return 0;
    
}