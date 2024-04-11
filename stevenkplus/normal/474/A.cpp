#include <cstdio>

char *key = "qwertyuiopasdfghjkl;zxcvbnm,./";

char str[1000];
char first;
int mp[1000];

int main() {
  for(int i = 0; key[i]; ++i) {
    mp[key[i]] = i;
  }


  scanf(" %c", &first);
  scanf("%s", str);

  for(int i = 0; str[i]; ++i) {
    int x = mp[str[i]];
    if (first == 'L') {
      ++x;
    } else {
      --x;
    }
    str[i] = key[x];
  }

  printf("%s\n", str);
}