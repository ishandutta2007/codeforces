#include <cstdio>
using namespace std;

char table[10];
char hand[10];
bool go() {
  scanf("%s", table);
  for (int i = 0; i < 5; ++i) {
    scanf("%s", hand + i * 2);
  }
  for(int i = 0; i < 10; ++i) {
    if (hand[i] == table[0] || hand[i] == table[1]) {
      return true;
    }
  }
  return false;
}

int main() {
  if (go()) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}