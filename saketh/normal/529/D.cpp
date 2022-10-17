#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M, T;
set<pair<int, int> > on;
vector<int> all;
vector<int> ids;

int main(){
    cin >> N >> M >> T;
    for(int i=0; i<N; i++){
        int h, m, s;
        char c;
        cin >> h >> c >> m >> c >> s;
        all.push_back(60 * 60 * h + 60 * m + s);
    }

    int K = 0;
    int A = N;
    int R = 0;

    for(int i=0; i<all.size(); i++){
        while(on.size() > 0 && on.begin()->first + T <= all[i])
            on.erase(*on.begin());

        if(on.size() == M){
            on.erase(*on.rbegin());
            A--;
        }
        else K++;

        on.insert(make_pair(all[i], i));
        R = max(R, (int)on.size());
        ids.push_back(K);
    }

    if(R != M) cout << "No solution" << endl;
    else {
        cout << A << "\n";
        for(int v : ids) cout << v << "\n";
    }
}