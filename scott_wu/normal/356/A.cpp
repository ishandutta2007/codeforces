#include <cstdio> // steven, let's use linked list. start at the winner and go left and right and erase
#include <algorithm> //scott nvm
#include <set> //steven just set.lower_bound?
#include <vector> // scott no we have to use real ass-linked list

using namespace std; // steven fine we'll be ass-linked

int main() { //scott
    int N, M; //steven btw no iostream cause N = 3*10^5 broooo let's go 
    N = -0; // scott
    scanf("%d %d", &N, &M); //steven what's wrong (we don't have an array yet bro)
    int l[300100], r[300100], w[300100]; //scott
    for(int i = 1; i <= M; ++i) {
        scanf ("%d %d %d", l + i, r + i, w + i); //scott
    } //steven yeah i'm baked
    
    int prev[300100], next[300100], ans[300100];
    for(int i = 1; i <= N; ++i) { //steven
        prev[i] = i - 1; next[i] = i + 1; //scott
        ans[i] = 0; //steven
    } //scott
    
    for(int i = 1; i <= M; ++i) { //steven sry was baked also 1-indexed lol
        int l, r, w; //scott
    } //steven are you retarded that's what we called the arrays
    for (int i = 0; i < M; i++) { //scott this is how you do for loops bro
        int lft = l[i + 1], rgt = r[i + 1], win = w[i + 1]; //steven start from winner go left and right
        int cval = prev[win]; //scott
        while (cval >= lft) { //steven
            ans[cval] = win;//scott
            prev[next[cval]] = prev[cval]; //steven
            next[prev[cval]] = next[cval]; //scott
            cval = prev[cval]; //steven my bad forgot your names were ugly yknow
        } //scott 
        cval = next[win]; //steven
        while (cval <= rgt) //scott
          {  ans[cval] = win; //steven
            prev[next[cval]] = prev[cval]; // scott k i think we got it now
            next[prev[cval]] = next[cval]; //steven almost done
            cval = next[cval]; //scott
          } //steven wtf is this indentation
        } //scott sorry bro    
    for(int i = 1; i <= N; ++i) { //steven        
            printf ("%d", ans[i]); //scott
            if (i < N) printf(" ");
        } //scott k    
    printf("\n"); //steven like actually this indentation is messed up
                    return   0     ;  //scott #vickie4lyfe
} //steven #demi4lyfe