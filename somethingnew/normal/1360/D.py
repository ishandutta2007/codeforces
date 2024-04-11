from math import sqrt
def main():
    n, k = map(int, input().split())
    if k >= n:
        print(1)
        return
    sv = 1
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            if n // i <= k:
                print(i)
                return
            if i <= k:
                sv = max(sv, i)
    print(n//sv)
for t in range(int(input())):
    main()