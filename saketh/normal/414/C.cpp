#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N, M, a[1<<25];
ll ti = 0;
ll v[25][2];
bool rev[25];

vector<int> calc(int x, int y, int d){
    if(x == y)
        return vector<int>(1, a[x]);

    int hw = (y - x + 1)/2;
    vector<int> left = calc(x, x+hw-1, d+1);
    vector<int> right = calc(x+hw, y, d+1);

    left.push_back(0x7fffffff);
    right.push_back(0x7fffffff);

    for(int i=0, j=0; i<hw || j<hw;){
        if(left[j] < right[i]){
            v[d][1] += hw - i;
            j++;
        }
        else i++;
    }

    ll here = 0;

    vector<int> res;
    for(int i=0, j=0; i<hw || j<hw;){
        if(right[j] < left[i]){
            here += hw - i;
            res.push_back(right[j++]);
        }
        else res.push_back(left[i++]);
    }

    v[d][0] += here;
    ti += here;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<(1<<N); i++)
        cin >> a[i];
    calc(0, (1<<N)-1, 0);

    cin >> M;
    for(int i=0; i<M; i++){
        int Q; cin >> Q;
        for(int j=N; j>=(N-Q); j--){
            ti += v[j][!rev[j]] - v[j][rev[j]];
            rev[j] = !rev[j];
        }
        cout << ti << "\n";
    }
    cout.flush();
    return 0;
}