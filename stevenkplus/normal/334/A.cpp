//kk let's finish A it should be easy
#include <cstdio> 

int N; //steven, we'll use scanf today.
using namespace std; //julia yeah i still have no idea //do i get rid of this line

int main() //steven you do the { i'll do the scanf, we don't need using namespace std unless we use stl which is like pair, cin, cout, set, map, vector, string, etc
{ //julia 
scanf("%d", &N); //steven, average = i have no clue.
for (int i = 1; i <= N; ++i) { //cout  0N+i, 2N-i+1, 2N+i, 4N-i+1, 4N+i etc. how do i cout wth do i 
for(int j = 1; j <= N; ++j) {//steven, you do the math lolll (n^2+1)/2 is average. ok print your thingy it seems legit (i actually don't know i'm trusting you) actually it looks weird go for it i have no idea lolol
if (j % 2 == 1) { //julia 
printf("%d ", (j-1) * N + i); // LOL I FAIL AT COMMENTING /steven i thought yo uwere going to do the hard part :(
}else { //julia LOL SUCKS 
printf("%d ", j * N - i + 1); //steven, does this even work idk rgiht my bad j is 1-index lol
} //julia ending else
} //steven, need one more i think right right we're done wait need cout << "\n". 
printf("\n"); //julia jk just testing you
} //steven 
return 0; //julia
} //steven good job
//compilation error we were gonna use printf woops
//yeah i was gonna ask and then i was very confused


//my bad i forgot, still compilation error woops this is right omg you can keep it shouldn't matter
// ok what is wrong omg we need cstdio, is it like we missed a {} i++ is fine