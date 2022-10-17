#include <map>
#include <iostream>
#include <vector>
using namespace std;

int N, V;
vector<int> v;
map<int, map<int, char> > out; 

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> V;
        v.push_back(V);
    }

    int sum = 0;    
    int y = 0, ymin = 0, ymax = 0;
    for(int i=0; i<v.size(); i++){
        
        for(int j=sum; j<sum+v[i]; j++){
            int top = y + !(i % 2);
            out[top][j] = (i % 2)?'\\':'/';

            y += (i%2)?(-1):1;
        }
        
        ymin = min(ymin, y);
        ymax = max(ymax, y);
        sum += v[i];
    }

    for(int row = ymax; row > ymin; row--){
        for(int col = 0; col < sum; col++)
            if(out[row].count(col)) cout << out[row][col];
            else cout << " ";
        cout << endl;
    }

    return 0;
}