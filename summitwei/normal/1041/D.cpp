#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_PER 200005
#define MAX_N 200005

pii air[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;
    for(int i=0; i<n; i++){
        cin >> air[i].first >> air[i].second;
    }

    int height = h;
    int proc = 0;
    while(proc < n && height > air[proc+1].first-air[proc].second){
        height -= (air[proc+1].first-air[proc].second);
        proc++;
    }

    int left = 0;

    //cout << "from 0 point, you can go up to " << air[proc].second+height << "\n";
    int maxh = air[proc].second+height-air[0].first;

    while(proc < n){
        height += air[left+1].first-air[left].second;
        left++;

        while(proc < n && height > air[proc+1].first-air[proc].second){
            height -= (air[proc+1].first-air[proc].second);
            proc++;
        }

        maxh = max(maxh, air[proc].second+height-air[left].first);
    }

    cout << maxh << "\n";

    return 0;
}