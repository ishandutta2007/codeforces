//order: travis, michael
#include <cstdio> //travis, so formula is (1-k/100)*t1*a + t2*b, we shoud multiply everything by 100
#include <algorithm> // yeah, sounds good.  we should also write a comparator (for indices i guess) so we can std::sort at the end
using namespace std; // yes i agree

int mushroom_size[1000]; // global so we can write comparator
bool cmp(int a, int b) { //i actually liked struct better, oh well
    if (mushroom_size[a] < mushroom_size[b]) {
        return false; } // travis
    else if (mushroom_size[a] > mushroom_size[b]) {
        return true; } // travis
    else {
return a < b; } // travis
}
int indices[1000]; // the array that we'll sort
int main() {
    int n, t1, t2, k; // travis
    scanf("%d%d%d%d", &n, &t1, &t2, &k);
    for (int i = 0; i < n; i++) { // travis, read input?
    } // into what?
    int a, b; for (int i = 0; i < n; i++) { // into those
        scanf("%d%d", &a, &b); // oh, i'm an idiot, i was thinking of reaidng them into arrays but it's not needed

        mushroom_size[i] = max((100-k)*t1*a + 100*t2*b, (100-k)*t1*b + 100*t2*a); // now initialize indicies
        indices[i] = i;
    } // travis: now sort
    sort(indices, indices+n, cmp);
    for (int i = 0; i < n; i++) { // travsi
        //printf("%d %d.%d\n", indices[i] + 1, mushroom_size[indices[i]]/100, mushroom_size[indices[i]]%100);
        printf("%d %d.%d%d\n", indices[i] + 1, mushroom_size[indices[i]]/100, (mushroom_size[indices[i]]%100)/10, mushroom_size[indices[i]]%10); // travis
    } // whoops
} // done