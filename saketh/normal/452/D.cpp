#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int K;
int A, B, C;
int X, Y, Z;

int T;
deque<int> v1, v2, v3;

int count_elt(deque<int> &d, int l, int r){
    if(d.size() == 0) return 0;
    if(l > d.back() || r < d.front()) return 0;
    auto f = (l < d.front() ? d.begin() : lower_bound(d.begin(), d.end(), l));
    auto e = (r > d.back() ? d.end() : upper_bound(d.begin(), d.end(), r));
    return e - f;    
}

bool can_push(){
    if(count_elt(v1, T-A+1, T) == X) return false; 
    if(count_elt(v1, T+A-A-B+1, T) + count_elt(v2, T+A-B+1, T) == Y) return false;
    if(count_elt(v1, T+A+B-A-B-C+1, T) + count_elt(v2, T+A+B-B-C+1, T) + count_elt(v3, T+A+B-C+1, T) == Z) return false;
    return true;
}

int main(){
    cin >> K >> X >> Y >> Z >> A >> B >> C;

    while(K || v1.size() || v2.size() || v3.size()){
        if(K && can_push()){
            K--;
            v1.push_back(T);
            continue;
        }
        else{
            T++;
            while(v1.size() && v1.front()+A == T){
                v2.push_back(T);
                v1.pop_front();
            }
            while(v2.size() && v2.front()+B == T){
                v3.push_back(T);
                v2.pop_front();
            }
            while(v3.size() && v3.front()+C == T){
                v3.pop_front();
            }
        }
    }

    cout << T << endl; 
}