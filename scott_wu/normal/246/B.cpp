#include <iostream> //ray, ill chose problem
#include <iomanip> //scott no dawg http://www.codeforces.com/problemset/problem/246/B
#include <cstring> //ray, ok reading
#include <algorithm> //scott so i think ans is just either N-1 or N based on whether sum is divisible by N

using namespace std; //ray yeah yeah ok gogoait this is hella trivial

int main() { //scott
    int N; cin >> N; //ray
    int arr[100100]; //scott

    for (int i=0; i<N; i++) //ray fuck you we dont need arr
    { cin >> arr[i]; } //scott no dawg
    int sum = 0; //ray oops we needed sum
    for (int i = 0; i < N; i++) sum += arr[i]; //scott
    
    cout << (sum % N == 0 ? N : N - 1) << "\n"; //ray
    return 0; //scott
} //ray