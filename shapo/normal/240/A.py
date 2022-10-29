#!/usr/bin/env python3


def main(fin, fout):
    m, k = list(map(int, fin.readline().split()))
    is_good = [0] * (m + 1)
    for good_id in map(int, fin.readline().split()):
        is_good[good_id] = 1
    n = int(fin.readline())
    min_actors, max_actors = [], []
    for _ in range(n):
        _ = fin.readline()
        d = int(fin.readline())
        n_good, n_bad, other = 0, 0, 0
        for actor in map(int, fin.readline().split()):
            if not actor:
                other += 1
            elif is_good[actor]:
                n_good += 1
            else:
                n_bad += 1
        left_good = k - n_good
        left_bad = (m - k) - n_bad
        min_good = n_good + other - min(other, left_bad)
        max_good = n_good + min(other, left_good)
        min_actors.append(min_good)
        max_actors.append(max_good)
    for idx in range(n):
        other_films_min = max(min_actors[:idx] + min_actors[idx+1:] + [-1])
        other_films_max = max(max_actors[:idx] + max_actors[idx+1:] + [-1])
        if other_films_max <= min_actors[idx]:
            print('0', file=fout)
        elif other_films_min > max_actors[idx]:
            print('1', file=fout)
        else:
            print('2', file=fout)


if __name__ == '__main__':
    with open('input.txt', 'r') as fin, open('output.txt', 'w') as fout:
        main(fin, fout)