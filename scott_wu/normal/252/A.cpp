//} scott
#include <cstdio> //steven
#include <cstring> //ray
#include <iostream> //scott
//#include <algorithm> steven

using namespace std; //ray, steven your line has a bug, no changing it now
typedef long long ll; //scott damn we can't use algorithm now

int max(int a, int b) { //steven sorry my bad
    return (a > b ? a : b); } //ray

int main() //scott
{//steven lol what it's my turn right
    int N; //ray, naw nigga
cin >> N; //scott
    int *ar = new int[N]; //steven wtf am i doing
    int cur = 0; //ray what?
for (int i = 0; i < N; i++) //scott
scanf("%d", ar + i); //steven 
for(int i=0; i<N; i++){ //ray, wait actually jk
int cval = 0; //scott
for(int j = i; j < N; ++j) {//steven did i mess up
cval = cval ^ ar[j]; //ray, what
cur = max (cur, cval);} //scott wait is the cin and scanf gonna be a problem
} cout << cur; printf("\n"); //steven
} //ray