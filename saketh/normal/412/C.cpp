#include<iostream>
#include<set>
using namespace std;

int N;
string v[100005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> v[i];
    for(int i=0; i<v[0].length(); i++){
        set<char> vals;
        vals.clear();
        for(int j=0; j<N; j++){
            if(v[j][i] != '?')
                vals.insert(v[j][i]);
        }
        if(vals.size() > 1) cout << '?';
        else if(vals.size() == 1) cout << *(vals.begin());
        else cout << 'x';
    }
    cout << endl;
    return 0;
}