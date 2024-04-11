from collections import defaultdict as dd

def case():
    n = int(input())
    a = sorted(list(map(int, input().split())))
    res = 0
    l = 0
    for pw in range(1, 31):
        r = l
        while r < n and a[r] < (1 << pw):
            r += 1
        cnt = r - l
        res += cnt * (cnt - 1) // 2
        l = r
    print(res)
        

def main():
    t = int(input())
    for _ in range(t):
        case()
        

if __name__ == '__main__':
    main()