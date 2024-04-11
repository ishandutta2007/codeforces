#include <iostream>
#include <vector>
using namespace std;

int K;
int HS;
vector<pair<int, int> > e;

void form_half(){
    //connect special
    for(int i=0; i<K-1; i++)
       e.emplace_back(0, i+1); 
    //remaining edges
    for(int i=1; i<=K+1; i++){
        for(int j=i+1; j<=K+1; j++){
            if(i&1 && i<=K-1 && j==i+1) continue;
            e.emplace_back(i, j);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> K;
    if(!(K&1)){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    if(K == 1){
        cout << "2 1\n1 2\n";
        return 0;
    }

    form_half();    

    cout << 2 * (K+2) << " " << 2 * e.size() + 1 << endl;
    for(auto p : e) cout << 1+p.first << " " << 1+p.second << "\n";
    for(auto p : e) cout << 1+K+2+p.first << " " << 1+K+2+p.second << "\n";
    cout << 1 << " " << 1+K+2 << endl;
    return 0;    
}