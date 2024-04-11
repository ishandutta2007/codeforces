#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n,k;
int num[105],a[105];
vector<P> res;

P getExt(){
    int mxi = 0, mni = 0;
    for(int i = 0; i < n; i++){
        if(num[i] > num[mxi]) mxi = i;
        if(num[i] < num[mni]) mni = i;
    }
    return P(mxi, mni);
}

int dif(){return num[getExt().first] - num[getExt().second];}

void sv(){for(int i = 0; i < n; i++) a[i] = num[i];}
void ld(){for(int i = 0; i < n; i++) num[i] = a[i];}

int main(){
    cin >> n >> k;
    int mx = num[0], mn = num[0];
    for(int i = 0; i < n; i++){
        cin >> num[i];
        a[i] = num[i];
        mx = max(mx, num[i]), mn = min(mn, num[i]);
    }

    for(int t = 0; t < k; t++){
        int mxi = getExt().first, mni = getExt().second;
        num[mxi]--, num[mni]++;
    }
    int mxi2 = getExt().first, mni2 = getExt().second;
    int minres = num[mxi2] - num[mni2];

    ld();
    for(int t = 0; t < k; t++){
        if(dif() == minres) break;
        int mxi = getExt().first, mni = getExt().second;
        num[mxi]--, num[mni]++;
        res.push_back(P(mxi+1, mni+1));
    }
    cout << minres << " " << res.size() << endl;
    for(P p : res){
        cout << p.first << " " << p.second << endl;
    }
}