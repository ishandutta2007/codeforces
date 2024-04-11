def main():
    n = int(input())
    lst = list(map(int, input().split()))
    b0 = 0
    b1 = 0
    for i in range(n):
        if i % 2 and lst[i] % 2 == 0:
            b0 += 1
        if i % 2 == 0 and lst[i] %2:
            b1 += 1
    if b0 != b1:
        print(-1)
    else:
        print(b0)

for t in range(int(input())):
    main()