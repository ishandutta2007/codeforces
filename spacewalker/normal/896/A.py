from functools import lru_cache
import sys

f0 = "What are you doing at the end of the world? Are you busy? Will you save us?"
fnext = ['What are you doing while sending "', '"? Are you busy? Will you send "', '"?']
BIG = 10**20

@lru_cache(maxsize=None)
def flength(n):
    if n == 0:
        return len(f0)
    else:
        sublen = flength(n-1)
        return min(BIG, sum([len(part) for part in fnext]) + 2 * sublen)

def get_char(n, k):
    while True:
        if k >= flength(n):
            return '.'
        if n == 0:
            return f0[k]

        for part in fnext:
            if k < len(part):
                return part[k]
            else:
                k -= len(part)

            if k < flength(n-1):
                n -= 1
                break
            else:
                k -= flength(n-1)
            
q = int(input())

for i in range(2 * 10**5):
    flength(i)

for _ in range(q):
    n, k = map(int, input().split())
    print(get_char(n, k-1), end="")
print("")