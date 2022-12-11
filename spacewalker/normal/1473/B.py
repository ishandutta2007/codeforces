from math import gcd

q = int(input())
for tc in range(q):
    a = input()
    b = input()
    anslen = len(a) * len(b) // gcd(len(a), len(b))
    shouldAns = a * (anslen // len(a))
    if (anslen // len(b)) * b == shouldAns:
        print(shouldAns)
    else:
        print(-1)