#include <iostream>
#include <vector>
using namespace std;

int r, tr;
char c, tc;
vector<string> moves;

int main(){
    cin >> c >> r >> tc >> tr;

    while(r!=tr || c!=tc){
        string m = "";
        if(c!=tc){
            if(c<tc) m+="R", c++;
            else m+="L", c--;
        }
        if(r!=tr){
            if(r<tr) m+= "U", r++;
            else m+= "D", r--;
        }
        moves.push_back(m);
    }

    cout << moves.size() << endl;
    for(string m : moves) cout << m << endl;
    return 0;
}