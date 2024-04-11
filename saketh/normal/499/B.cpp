#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, string> dict;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0; i<M; i++){
        string a, b;
        cin >> a >> b;
        dict[a] = b;
    }
    
    for(int i=0; i<N; i++){
        string w;
        cin >> w;
        cout << (w.length()>dict[w].length()?dict[w]:w) << "\n";
    }

    cout.flush();
    return 0;
}