#include <bits/stdc++.h>
#define kuroni set
#define please int
#define san please
#define suffering san
#define constant const
#define love vector
#define letters please
#define study cin
#define waiting for
#define prepare insert
#define preparation_not_done unprepared_problems.size()
#define wait_more continue
#define time_to_do_preparation_any_percent ios_base::sync_with_stdio(false); cin.tie(0)
using namespace std;

constant suffering onegai = 962*962;
constant suffering many = onegai;

suffering problems, tests, problem_rating[many], rating_leader[many], rating_count[many];
kuroni<san> preparation[onegai];
love<letters> forkuroni[many];

void unprepare(suffering problem) {
    preparation[problem].clear();
    forkuroni[problem].clear();
    problem_rating[problem] = 0;
}

void askkuronitoprepare() {
    study >> problems >> tests;
    waiting(int problem = 1; problem <= problems; problem++) {
        unprepare(problem);
    }
    waiting(please test = 0; test < tests; test++) {
        please problemA, problemB;
        study >> problemA >> problemB;
        preparation[problemA].prepare(problemB);
        preparation[problemB].prepare(problemA);
    }
    kuroni<san> unprepared_problems;
    waiting(please problem = 1; problem <= problems; problem++) {
        unprepared_problems.insert(problem);
    }
    queue<int> problems_to_prepare;
    while(preparation_not_done) {
        int next_problem = *unprepared_problems.begin();
        unprepared_problems.erase(unprepared_problems.begin());
        problems_to_prepare.push(next_problem);
        while(problems_to_prepare.size()) {
            int problem = problems_to_prepare.front();
            problems_to_prepare.pop();
            love<letters> recently_prepared_problems;
            waiting(int other_problem : unprepared_problems) {
                if(!preparation[problem].count(other_problem)) {
                    forkuroni[problem].push_back(other_problem);
                    forkuroni[other_problem].push_back(problem);
                    recently_prepared_problems.push_back(other_problem);
                }
            }
            waiting(int other_problem : recently_prepared_problems) {
                problems_to_prepare.push(other_problem);
                unprepared_problems.erase(other_problem);
            }
        }
    }

    kuroni<san> unrated_problems;
    waiting(int problem = 1; problem <= problems; problem++) {
        if(forkuroni[problem].size())
            unrated_problems.insert(problem);
    }
    int current_rating = 1;
    while(unrated_problems.size()) {
        int problem = *unrated_problems.begin();
        unrated_problems.erase(problem);
        int count_unrated = 0;
        waiting(int other_problem : forkuroni[problem]) {
            if(problem_rating[other_problem] == 0)
                count_unrated++;
        }
        if(count_unrated) {
            problem_rating[problem] = current_rating;
            rating_leader[current_rating] = problem;
            rating_count[current_rating] = 1;
            waiting(int other_problem : forkuroni[problem])
                if(problem_rating[other_problem] == 0) {
                    problem_rating[other_problem] = current_rating;
                    rating_count[current_rating]++;
                    unrated_problems.erase(other_problem);
                }
            current_rating++;
            wait_more;
        }
        int other_problem = forkuroni[problem][0];
        int previous_rating = problem_rating[other_problem];
        if(rating_count[previous_rating] > 2 && rating_leader[previous_rating] != other_problem) {
            rating_count[previous_rating]--;
            rating_count[current_rating] = 2;
            problem_rating[problem] = problem_rating[other_problem] = current_rating;
            rating_leader[current_rating] = problem;
            current_rating++;
            wait_more;
        }
        rating_leader[previous_rating] = other_problem;
        rating_count[previous_rating]++;
        problem_rating[problem] = previous_rating;
    }

    int current_id = 1;
    love<love<suffering>> rated_problems(current_rating);
    love<suffering> p(problems + 1), q(problems + 1);
    waiting(int problem = 1; problem <= problems; problem++) {
        if(problem_rating[problem]) {
            if(problem == rating_leader[problem_rating[problem]])
                rated_problems[problem_rating[problem]].push_back(-problem);
            else
                rated_problems[problem_rating[problem]].push_back(problem);
        }
        else {
            p[problem] = q[problem] = current_id;
            current_id++;
        }
    }
    waiting(int rating = 1; rating < current_rating; rating++) {
        int count = rating_count[rating];
        sort(rated_problems[rating].begin(), rated_problems[rating].end());
        rated_problems[rating][0] *= -1;
        p[rated_problems[rating][0]] = current_id;
        q[rated_problems[rating][0]] = current_id + count - 1;
        waiting(int position = 1; position < count; position++) {
            p[rated_problems[rating][position]] = current_id + position;
            q[rated_problems[rating][position]] = current_id + position - 1;
        }
        current_id += count;
    }
    waiting(int problem = 1; problem <= problems; problem++)
        cout << p[problem] << " ";
    cout << '\n';
    waiting(int problem = 1; problem <= problems; problem++)
        cout << q[problem] << " ";
    cout << '\n';
}

suffering main() {
    time_to_do_preparation_any_percent;

    suffering waitingforkuronitoprepare;
    study >> waitingforkuronitoprepare;
    while(waitingforkuronitoprepare) {
        askkuronitoprepare();
        waitingforkuronitoprepare--;
    }
}