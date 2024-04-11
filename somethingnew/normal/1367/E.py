from math import gcd
def main():
    n, k  = map(int,input().split())
    st = input()
    alph = [0 for i in range(ord("z") - ord("a") + 1)]
    for i in st:
        alph[ord(i) - ord("a")] += 1
    for i in range(n, 0, -1):
        n2 = gcd(i, k)
        n1 = i // n2
        for j in alph:
            n2 -= (j//n1)
        if n2 <= 0:
            print(i)
            return

for t in range(int(input())):
    main()