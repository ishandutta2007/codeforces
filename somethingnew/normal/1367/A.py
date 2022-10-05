def main():
    st = input()
    stans = st[0]
    for i in range(1, len(st) - 1, 2):
        stans += st[i]
    stans += st[-1]
    print(stans)

for t in range(int(input())):
    main()