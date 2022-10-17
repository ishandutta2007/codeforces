#include <iostream>
#include <map>
using namespace std;

bool good;
map<int, int> st;

int main(){
    for(int i=0; i<6; i++){
        int k; cin >> k;
        st[k]++;
        if(st[k] == 4){ st.erase(k); good = true;}
    }

    if(!good) cout << "Alien" << endl;
    else if(st.size() == 1) cout << "Elephant" << endl;
    else cout << "Bear" << endl;
    return 0;
}