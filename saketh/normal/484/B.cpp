#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int main(){
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));

    int ans = 0;
    for(int i=0; i<v.size(); i++)
        for(int j=v[i]; j<=v.back(); j+=v[i]){
            int c = *(lower_bound(v.begin(), v.end(), j+v[i])-1);
            ans = max(ans, c - j);
        }

    cout << ans << endl;
    return 0;
}