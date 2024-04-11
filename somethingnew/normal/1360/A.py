def main():
    a, b = map(int,input().split())
    c = max(a,b)
    d = min(a,b)
    e = max(d*2, c)
    print(e*e)
for t in range(int(input())):
    main()