def compare(i, j):
    print('?', i + 1, j + 1, flush=True)
    x = int(input())
    print('?', j + 1, i + 1, flush=True)
    y = int(input())
    return x, y


def main():
    n = int(input())
    p = [-1] * n
    argmax = 0
    for i in range(1, n):
        x, y = compare(argmax, i)
        if x > y:
            p[argmax] = x
            argmax = i
        else:
            p[i] = y
    p[argmax] = n
    print('!', *p)


if __name__ == '__main__':
    main()