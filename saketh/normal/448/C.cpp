#include <iostream>
#include <vector>
using namespace std;

int N, v[5005];

int solve(int l, int r, int h){
    if(r<l) return 0;

    int vert = r - l + 1;

    int low = 1000000000;
    for(int i=l; i<=r; i++)
        low = min(low, v[i]);

    int add = low - h;

    vector<int> locs;
    locs.push_back(l-1);
    for(int i=l; i<=r; i++)
        if(v[i] == low)
            locs.push_back(i);
    locs.push_back(r+1);

    int ans = add;
    for(int i=1; i<locs.size(); i++)
        ans += solve(locs[i-1]+1, locs[i]-1, low);

    return min(ans, vert);
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> v[i];

    cout << solve(0, N-1, 0) << endl;
    return 0;
}