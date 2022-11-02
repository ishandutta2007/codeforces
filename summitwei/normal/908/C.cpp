#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int N, R;
    cin >> N >> R;
    vector<int> xCoords(N);
    for(int i=0; i<N; i++){
        cin >> xCoords[i];
    }

    vector<pair<double, double>> endLocs(N, make_pair(-2*R, 2*R));

    for(int i=0; i<N; i++){
        double topY = R;
        for(int j=0; j<i; j++){
            double diff = abs(xCoords[i] - endLocs[j].first);
            if(diff > 2*R){
                continue;
            }
            double newAmt = sqrt(4*R*R-diff*diff) + endLocs[j].second;
            if(newAmt > topY){
                topY = newAmt;
            }
        }

        endLocs[i] = make_pair(xCoords[i], topY);
    }
    
    for(int i=0; i<N-1; i++){
        cout << setprecision(12) << endLocs[i].second << " ";
    }
    cout << setprecision(12) << endLocs[N-1].second;

    return 0;
}